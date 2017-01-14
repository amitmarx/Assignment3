package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.DeleteRequest;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

public class DeleteRequestCommandBuilder implements CommandBuilder {
    StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        String fileName = stringEncoderDecoder.decodeNextByte(nextByte);
        if(fileName!=null){
            return new DeleteRequest(fileName);
        }
        return null;
    }
}
