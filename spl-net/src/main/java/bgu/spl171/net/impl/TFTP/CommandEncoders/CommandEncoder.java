package bgu.spl171.net.impl.TFTP.CommandEncoders;

import bgu.spl171.net.impl.TFTP.Commands.Command;

public interface CommandEncoder {
    byte[] encode(Command cmd);
    static CommandEncoder get(short opCode){
        switch (opCode){
            case 3: return new DataCommandEncoder();
            case 4: return new AckCommandEncoder();
            //Todo: handle errors
            //case 5: return new ErrorCommandEncoder();
            case 9: return new BroadcastCommandEncoder();
        }
        //Todo make an error
        return null;
    }
}
