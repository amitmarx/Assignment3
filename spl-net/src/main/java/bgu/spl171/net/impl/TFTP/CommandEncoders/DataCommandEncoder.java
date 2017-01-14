package bgu.spl171.net.impl.TFTP.CommandEncoders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Data;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;

public class DataCommandEncoder implements CommandEncoder {

    private ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();
    @Override
    public byte[] encode(Command cmd) {
        Data data = (Data)cmd;
        byte[] opCode = shortEncoderDecoder.encode((short)3);
        byte[] size = shortEncoderDecoder.encode(data.getSize());
        byte[] blockId = shortEncoderDecoder.encode(data.getBlockId());
        return EncoderUtils.mergeByteArray(opCode,size,blockId,data.getData(),new byte[]{0});
    }
}
