package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class DisconnectRequest implements Command {

    @Override
    public short getOpCode() {
        return OpCode.Disconnect.getValue();
    }

}
