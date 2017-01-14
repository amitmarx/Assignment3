package bgu.spl171.net.impl.TFTP.EncoderDecoders;

import bgu.spl171.net.api.MessageEncoderDecoder;
import bgu.spl171.net.impl.TFTP.CommandBuilders.CommandBuilder;
import bgu.spl171.net.impl.TFTP.CommandEncoders.CommandEncoder;
import bgu.spl171.net.impl.TFTP.Commands.Command;

import java.nio.ByteBuffer;

public class TFTPEncoderDecoder implements MessageEncoderDecoder<Command> {

    ShortEncoderDecoder shortEncoderDecoder = new ShortEncoderDecoder();
    CommandBuilder builder = null;

    @Override
    public Command decodeNextByte(byte nextByte) {
        Command returnValue = null;

        if (builder == null) {
            Short opCode = shortEncoderDecoder.decodeNextByte(nextByte);
            if (opCode != null) {
                builder = CommandBuilder.createBuilder(opCode);
                if (builder == null) {
                    returnValue = CommandBuilder.createCommand(opCode);
                }
            }
        } else {
            returnValue = builder.decodeNextByte(nextByte);
            if (returnValue != null) {
                builder = null;
            }
        }
        return returnValue;
    }

    @Override
    public byte[] encode(Command message) {
        return CommandEncoder.get(message.getOpCode()).encode(message);
    }

}
