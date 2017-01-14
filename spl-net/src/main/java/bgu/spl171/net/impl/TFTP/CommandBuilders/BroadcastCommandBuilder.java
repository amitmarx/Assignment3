package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.ReadRequest;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

public class BroadcastCommandBuilder implements CommandBuilder {
    Boolean isAdded = null;
    StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        if (isAdded != null) {
            String fileName = stringEncoderDecoder.decodeNextByte(nextByte);
            if (fileName != null) {
                return new ReadRequest(fileName);
            }
        }
        else {
            isAdded = nextByte == 1;
        }
        return null;
    }
}
