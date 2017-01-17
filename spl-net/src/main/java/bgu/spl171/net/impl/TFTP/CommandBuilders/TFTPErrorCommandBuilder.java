package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Responses.TFTPError;
import bgu.spl171.net.impl.TFTP.Commands.WriteRequest;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

public class TFTPErrorCommandBuilder implements CommandBuilder {
    Short errorCode = null;
    ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        if (errorCode == null) {
            errorCode = shortEncoderDecoder.decodeNextByte(nextByte);
        } else {
            String errorMsg = stringEncoderDecoder.decodeNextByte(nextByte);
            if (errorMsg != null) {
                return new TFTPError(errorCode, errorMsg);
            }
        }
        return null;
    }
}
