package bgu.spl171.net.impl.TFTP.EncoderDecoders;

import bgu.spl171.net.impl.TFTP.CommandEncoders.EncoderUtils;
import bgu.spl171.net.impl.TFTP.Commands.Command;
import bgu.spl171.net.impl.TFTP.Commands.ReadRequest;

import java.util.ArrayList;
import java.util.List;

public class StringEncoderDecoder {
    List<Byte> stringBuffer = new ArrayList<>();

    public String decodeNextByte(byte nextByte) {
        if (nextByte == 0) {
            String returnValue = getString();
            stringBuffer.clear();
            return returnValue;
        }
        return null;
    }

    private String getString() {
        byte[] bytes = new byte[stringBuffer.size()];
        for (int i = 0; i < bytes.length; i++) {
            bytes[i] = stringBuffer.get(i);
        }
        return new String(bytes);
    }
    public byte[] encode(String str){
        return EncoderUtils.mergeByteArray(str.getBytes(),new byte[]{0});
    }
}
