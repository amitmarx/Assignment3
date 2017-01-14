package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.ReadRequest;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

import java.util.ArrayList;
import java.util.List;

public class ReadRequestCommandBuilder implements CommandBuilder {

    StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        String fileName = stringEncoderDecoder.decodeNextByte(nextByte);
        if(fileName!=null){
            return new ReadRequest(fileName);
        }
        return null;
    }
}
