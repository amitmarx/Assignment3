package bgu.spl171.net.impl.TFTP.CommandEncoders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Ack;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;

public class AckCommandEncoder implements CommandEncoder {
    ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();
    @Override
    public byte[] encode(Command cmd) {
        Ack ack = (Ack) cmd;
        byte [] opCode =shortEncoderDecoder.encode((short)4);
        byte [] blockId = shortEncoderDecoder.encode(ack.getBlockId());
        return EncoderUtils.mergeByteArray(opCode,blockId);
    }
}
