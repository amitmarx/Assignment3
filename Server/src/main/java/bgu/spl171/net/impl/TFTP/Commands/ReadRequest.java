package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class ReadRequest implements Command {

    String fileName;
    public ReadRequest(String fileName) {
        this.fileName = fileName;
    }

    public String getFileName() {
        return fileName;
    }

    @Override
    public short getOpCode() {
        return OpCode.ReadRequest.getValue();
    }

    @Override
    public Response execute() {
        return null;
    }
}
