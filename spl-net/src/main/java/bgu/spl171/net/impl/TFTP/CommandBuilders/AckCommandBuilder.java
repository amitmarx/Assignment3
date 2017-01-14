package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Responses.Ack;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;

public class AckCommandBuilder implements CommandBuilder {
    ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        Short blockId = shortEncoderDecoder.decodeNextByte(nextByte);
        if(blockId!=null){
            return new Ack(blockId);
        }
        return null;
    }
}
