package bgu.spl171.net.impl.TFTP.CommandEncoders;

import bgu.spl171.net.impl.TFTP.Commands.Broadcast;
import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;

public class BroadcastCommandEncoder implements CommandEncoder {
    ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();
    @Override
    public byte[] encode(Command cmd) {
        Broadcast broadcast = (Broadcast) cmd;
        byte [] opCode = shortEncoderDecoder.encode((short)9);
        byte [] isAdded = broadcast.isAdded() ? new byte[]{(byte) 1} : new byte[]{(byte) 0};
        byte [] fileName = broadcast.getFileName().getBytes();

        return EncoderUtils.mergeByteArray(opCode,isAdded,fileName,new byte[]{0});

    }
}
