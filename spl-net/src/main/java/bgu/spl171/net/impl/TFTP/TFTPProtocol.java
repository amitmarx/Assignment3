package bgu.spl171.net.impl.TFTP;

import bgu.spl171.net.api.bidi.BidiMessagingProtocol;
import bgu.spl171.net.api.bidi.Connections;
import bgu.spl171.net.impl.TFTP.Commands.*;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Ack;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TFTPProtocol implements BidiMessagingProtocol<Command> {
    int connectionId;
    Connections<Command> connections;
    String fileName = null;
    List<Data> dataToWrite;
    Queue<Data> dataToSend = new ArrayDeque<>();
    String directory;

    @Override
    public void start(int connectionId, Connections<Command> connections) {
        this.connectionId = connectionId;
        this.connections = connections;
    }

    @Override
    public void process(Command message) {
        Response r;
        switch (message.getOpCode()){
            case 1 : r = handleReadRequest((ReadRequest) message);
                break;
            case 2 : r = handleWriteRequest((WriteRequest) message);
                break;
            case 3 : r = handleDataRequest((Data) message);
                break;
            case 4 : r = handleAck((Ack)message);
                break;
            case 5 : r = handleError((ErrorCommand)message);
                break;
            case 6 : r = handleDirlist((DirlistRequest)message);
                break;
        }
    }

    private Response handleDirlist(DirlistRequest message) {
        Collection<File> files = FileUtils.listFiles(new File(directory),null,true);
        StringBuilder dirlistBuilder = new StringBuilder();
        for(File f: files){
            dirlistBuilder.append(f.getName());
            dirlistBuilder.append('0');
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
        if(!Files.exists(Paths.get(fileName))){
            //Todo send an error
        }
        try {
            dataToWrite.add(message);
            if (message.isFinalMessage()) {
                for (Data data : dataToWrite) {
                    Files.write(Paths.get(fileName), data.getData());
                }
            }
        }
        catch (Exception e){
            //Todo send an error
        }
        return new Ack(message.getBlockId());
    }

    private Response handleWriteRequest(WriteRequest message) {
        if(!Files.exists(Paths.get(message.getFileName()))){
            //Todo send an error
        }
        fileName = message.getFileName();
        dataToWrite = new ArrayList<Data>();
        return new Ack((short)0);
    }

    private Response handleAck(Ack message) {
        if(dataToSend.size()>0){
            return dataToSend.poll();
        }

    }

    private Response handleReadRequest(ReadRequest message) {
        if(!Files.exists(Paths.get(message.getFileName()))){
            //Todo send an error
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
        }
        catch (Exception e){
            //Todo send an error
        }
        return dataToSend.poll();
    }

    @Override
    public boolean shouldTerminate() {
        return false;
    }

}
