package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class Broadcast implements Command {
    boolean isAdded;
    String fileName;

    public Broadcast(boolean isAdded, String fileName) {
        this.isAdded = isAdded;
        this.fileName = fileName;
    }

    public boolean isAdded() {
        return isAdded;
    }

    public String getFileName() {
        return fileName;
    }

    @Override
    public short getOpCode() {
        return OpCode.Broadcast.getValue();
    }

}
