package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class Data implements Response {
    short size;
    short blockId;
    byte[] data;

    public Data(short size, short blockId, byte[] data) {
        this.size = size;
        this.blockId = blockId;
        this.data = data;
    }

    public short getSize() {
        return size;
    }

    public short getBlockId() {
        return blockId;
    }

    public byte[] getData() {
        return data;
    }

    public boolean isFinalMessage() {
        return size < 512;
    }

    @Override
    public short getOpCode() {
        return OpCode.Data.getValue();
    }
}
