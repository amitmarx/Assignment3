package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.DirlistRequest;
import bgu.spl171.net.impl.TFTP.Commands.DisconnectRequest;

public interface CommandBuilder {
    Command decodeNextByte(byte nextByte);
    static CommandBuilder createBuilder(short opCode){
        switch (opCode){
            case 1: return new ReadRequestCommandBuilder();
            case 2: return new WriteRequestCommandBuilder();
            case 3: return new DataCommandBuilder();
            case 5: return new TFTPErrorCommandBuilder();
            case 4: return new AckCommandBuilder();
            case 7: return new LoginRequestCommandBuilder();
            case 8: return new DeleteRequestCommandBuilder();
            case 9: return new BroadcastCommandBuilder();
        }
        //Todo make an error
        return null;
    }

    static Command createCommand(short opCode) {
        switch (opCode){
            case 6: return new DirlistRequest();
            case 10: return new DisconnectRequest();
        }
        return null;
    }
}
