package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Data;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;

public class DataCommandBuilder implements CommandBuilder {
    Short size = null;
    Short blockId = null;
    private byte[] data;
    private int index = 0;
    private final ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        if (size == null) {
            size = shortEncoderDecoder.decodeNextByte(nextByte);
            data = new byte[size];
        } else if (blockId == null) {
            blockId = shortEncoderDecoder.decodeNextByte(nextByte);
        } else {
            data[index] = nextByte;
            if (++index == size) {
                return new Data(size, blockId, data);
            }
        }
        return null;
    }
}
