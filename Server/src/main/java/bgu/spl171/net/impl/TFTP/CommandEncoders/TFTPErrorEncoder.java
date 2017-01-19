package bgu.spl171.net.impl.TFTP.CommandEncoders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.Responses.TFTPError;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.ShortEncoderDecoder;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

public class TFTPErrorEncoder implements CommandEncoder{
    private ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();
    private StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public byte[] encode(Command cmd) {
        TFTPError error = (TFTPError) cmd;
        byte[] opCode = shortEncoderDecoder.encode(error.getOpCode());
        byte[] errorCode = shortEncoderDecoder.encode(error.getErrorCode());
        byte[] errorMsg = stringEncoderDecoder.encode(error.getErrorMessage());
        return EncoderUtils.mergeByteArray(opCode,errorCode,errorMsg);
    }
}
