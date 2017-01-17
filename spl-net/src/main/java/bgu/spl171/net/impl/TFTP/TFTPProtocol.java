package bgu.spl171.net.impl.TFTP;

import bgu.spl171.net.api.bidi.BidiMessagingProtocol;
import bgu.spl171.net.api.bidi.Connections;
import bgu.spl171.net.impl.TFTP.Commands.*;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Ack;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;
import bgu.spl171.net.impl.TFTP.Commands.Responses.TFTPError;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class TFTPProtocol implements BidiMessagingProtocol<Command> {
    int connectionId;
    String username;
    Connections<Command> connections;
    String fileName = null;
    List<Data> dataToWrite;
    Queue<Data> dataToSend = new ArrayDeque<>();
    File directory;
    Boolean isLoggedIn = false;
    Boolean shouldTerminate = false;
    TFTPLoggedUsers loggedUsers;

    public TFTPProtocol(TFTPLoggedUsers loggedUsers, String filesDir) {
        this.loggedUsers = loggedUsers;
        directory = Paths.get(filesDir).toFile();
    }

    @Override
    public void start(int connectionId, Connections<Command> connections) {
        this.connectionId = connectionId;
        this.connections = connections;
    }

    @Override
    public void process(Command message) {
        Response response = null;
        if (isLoggedIn || message.getOpCode() == 7) {
            switch (message.getOpCode()) {
                case 1:
                    response = handleReadRequest((ReadRequest) message);
                    break;
                case 2:
                    response = handleWriteRequest((WriteRequest) message);
                    break;
                case 3:
                    response = handleDataRequest((Data) message);
                    break;
                case 4:
                    response = handleAck((Ack) message);
                    break;
                case 5:
                    response = handleError((TFTPError) message);
                    break;
                case 6:
                    response = handleDirlist((DirlistRequest) message);
                    break;
                case 7:
                    response = handleLoginRequest((LoginRequest) message);
                    break;
                case 8:
                    response = handleDeleteRequest((DeleteRequest) message);
                    break;
                case 10:
                    response = handleDisconnectRequest((DisconnectRequest) message);
                    break;
            }
        } else {
            response = new TFTPError(6);
        }
        if (response != null) {
            connections.send(connectionId,response);
        }
    }

    private Response handleError(TFTPError message) {
        dataToSend = new ArrayDeque<>();
        fileName = null;
        return null;
    }

    private Response handleDisconnectRequest(DisconnectRequest message) {
        loggedUsers.remove(username);
        shouldTerminate = true;
        return new Ack();
    }

    private Response handleDeleteRequest(DeleteRequest message) {
        try {
            if (Files.deleteIfExists(Paths.get(message.getFileName()))) {
                connections.broadcast(new Broadcast(false, message.getFileName()));
                return new Ack();
            }
        } catch (Exception e) {

        }
        return new TFTPError(2);

    }

    private Response handleLoginRequest(LoginRequest message) {
        if (this.isLoggedIn) {
            return new TFTPError(7);
        }

        if (loggedUsers.add(message.getUsername())) {
            isLoggedIn = true;
            this.username = message.getUsername();
            return new Ack();
        } else {
            return new TFTPError(7);
        }
    }

    private Response handleDirlist(DirlistRequest message) {
        Collection<File> files = FileUtils.listFiles(directory, null, true);
        StringBuilder dirlistBuilder = new StringBuilder();
        for (File f : files) {
            dirlistBuilder.append(f.getName());
            dirlistBuilder.append('\0');
        }

        byte[] dirlistInBytes = dirlistBuilder.toString().getBytes();
        int blocks = dirlistInBytes.length / 512;
        for (short block = 0; block < blocks; block++) {
            byte[] data = Arrays.copyOfRange(dirlistInBytes, block * 512, (block + 1) * 512 - 1);
            Data cmd = new Data((short) data.length, block, data);
            dataToSend.add(cmd);
        }
        int modulo = dirlistInBytes.length % 512;
        int startPos = blocks * 512;
        byte[] data = Arrays.copyOfRange(dirlistInBytes, startPos, startPos + modulo);
        Data cmd = new Data((short) data.length, (short) (blocks + 1), data);
        dataToSend.add(cmd);
        return dataToSend.poll();
    }

    private Response handleDataRequest(Data message) {
        if (directory.getTotalSpace() < message.getSize()) {
            return new TFTPError(3);
        }
        if (Files.exists(Paths.get(fileName))) {
            return new TFTPError(5);
        }
        try {
            dataToWrite.add(message);
            if (message.isFinalMessage()) {
                for (Data data : dataToWrite) {
                    Files.write(Paths.get(fileName), data.getData());
                }
                connections.broadcast(new Broadcast(true, fileName));
            }
        } catch (Exception e) {
            return new TFTPError(2);
        }
        return new Ack(message.getBlockId());
    }

    private Response handleWriteRequest(WriteRequest message) {
        if (!Files.exists(Paths.get(message.getFileName()))) {
            return new TFTPError(5);
        }
        fileName = message.getFileName();
        dataToWrite = new ArrayList<>();
        return new Ack();
    }

    private Response handleAck(Ack message) {
        if (dataToSend.size() > 0) {
            return dataToSend.poll();
        }
        return null;
    }

    private Response handleReadRequest(ReadRequest message) {
        if (!Files.exists(Paths.get(message.getFileName()))) {
            return new TFTPError(1);
        }
        try {
            byte[] fileInBytes = Files.readAllBytes(Paths.get(message.getFileName()));
            int blocks = fileInBytes.length / 512;
            for (short block = 0; block < blocks; block++) {
                byte[] data = Arrays.copyOfRange(fileInBytes, block * 512, (block + 1) * 512 - 1);
                Data cmd = new Data((short) data.length, block, data);
                dataToSend.add(cmd);
            }
            int modulo = fileInBytes.length % 512;
            int startPos = blocks * 512;
            byte[] data = Arrays.copyOfRange(fileInBytes, startPos, startPos + modulo);
            Data cmd = new Data((short) data.length, (short) (blocks + 1), data);
            dataToSend.add(cmd);
        } catch (Exception e) {
            return new TFTPError(2);
        }
        return dataToSend.poll();
    }

    @Override
    public boolean shouldTerminate() {
        return shouldTerminate;
    }

}
