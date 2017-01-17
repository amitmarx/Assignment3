package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.WriteRequest;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

public class WriteRequestCommandBuilder implements CommandBuilder {
    StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        String fileName = stringEncoderDecoder.decodeNextByte(nextByte);
        if(fileName!=null){
            return new WriteRequest(fileName);
        }
        return null;
    }
}
