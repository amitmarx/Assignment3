package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public interface Command {
    short getOpCode();

    enum OpCode{
        ReadRequest,
        WriteRequest,
        Data,
        Ack,
        Error,
        Dirlist,
        Login,
        Delete,
        Broadcast,
        Disconnect;

        public short getValue() {
            return (short)(ordinal() + 1);
        }
    }
}
