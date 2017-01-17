package bgu.spl171.net.impl.TFTP.Commands.Responses;

public class Ack implements Response {
    short blockId;

    public Ack(short blockId) {
        this.blockId = blockId;
    }
    public Ack() {
        this.blockId = (short)0;
    }

    public short getBlockId() {
        return blockId;
    }

    @Override
    public short getOpCode() {
        return OpCode.Ack.getValue();
    }

    @Override
    public Response execute() {
        return null;
    }
}
