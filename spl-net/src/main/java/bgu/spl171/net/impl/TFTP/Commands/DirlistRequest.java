package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class DirlistRequest implements Command {
    @Override
    public short getOpCode() {
        return OpCode.Dirlist.getValue();
    }

    @Override
    public Response execute() {
        return null;
    }
}
