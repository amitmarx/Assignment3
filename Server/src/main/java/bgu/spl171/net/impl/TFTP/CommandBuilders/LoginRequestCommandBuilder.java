package bgu.spl171.net.impl.TFTP.CommandBuilders;

import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.LoginRequest;
import bgu.spl171.net.impl.TFTP.Commands.ReadRequest;
import bgu.spl171.net.impl.TFTP.EncoderDecoders.StringEncoderDecoder;

public class LoginRequestCommandBuilder implements CommandBuilder {
    StringEncoderDecoder stringEncoderDecoder = new StringEncoderDecoder();

    @Override
    public Command decodeNextByte(byte nextByte) {
        String username = stringEncoderDecoder.decodeNextByte(nextByte);
        if (username != null) {
            return new LoginRequest(username);
        }
        return null;
    }
}
