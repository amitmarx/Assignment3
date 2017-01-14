package bgu.spl171.net.impl.TFTP;

import bgu.spl171.net.api.bidi.BidiMessagingProtocol;
import bgu.spl171.net.api.bidi.Connections;
import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Data;
import bgu.spl171.net.impl.TFTP.Commands.ReadRequest;

import java.util.HashMap;
import java.util.Queue;

public class TFTPProtocol implements BidiMessagingProtocol<Command> {
    int connectionId;
    Connections<Command> connections;
    Boolean isReading = false;
    Boolean isWriting = false;

    @Override
    public void start(int connectionId, Connections<Command> connections) {
        this.connectionId = connectionId;
        this.connections = connections;
    }

    @Override
    public void process(Command message) {
        if(isReading){
            ((Data)message)
        }
    }

    @Override
    public boolean shouldTerminate() {
        return false;
    }

    private void executeCommand(ReadRequest cmd){

    }
}
