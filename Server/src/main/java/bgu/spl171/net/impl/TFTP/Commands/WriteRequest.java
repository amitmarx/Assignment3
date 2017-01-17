package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class WriteRequest implements Command {

    String fileName;
    public WriteRequest(String fileName) {
        this.fileName = fileName;
    }

    public String getFileName() {
        return fileName;
    }

    @Override
    public short getOpCode() {
        return OpCode.WriteRequest.getValue();
    }

    @Override
    public Response execute() {
        return null;
    }
}
