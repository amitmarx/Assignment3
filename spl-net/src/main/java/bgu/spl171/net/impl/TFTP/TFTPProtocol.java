package bgu.spl171.net.impl.TFTP;

import bgu.spl171.net.api.bidi.BidiMessagingProtocol;
import bgu.spl171.net.api.bidi.Connections;
import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Data;
import bgu.spl171.net.impl.TFTP.Commands.ReadRequest;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Queue;

public class TFTPProtocol implements BidiMessagingProtocol<Command> {
    int connectionId;
    Connections<Command> connections;
    Queue<Data> dataToSend = new ArrayDeque<>();

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
        }
    }

    private Response handleReadRequest(ReadRequest message) {
        if(!Files.exists(Paths.get(message.getFileName()))){
            //Todo send an error
        }
    }

    @Override
    public boolean shouldTerminate() {
        return false;
    }

}
