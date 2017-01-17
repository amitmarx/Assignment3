package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class DeleteRequest implements Command {
    String fileName;

    public String getFileName() {
        return fileName;
    }

    public DeleteRequest(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public short getOpCode() {
        return OpCode.Delete.getValue();
    }

    @Override
    public Response execute() {
        return null;
    }
}
