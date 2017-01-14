package bgu.spl171.net.impl.TFTP.EncoderDecoders;

import java.nio.ByteBuffer;

public class ShortEncoderDecoder {
    private final ByteBuffer shortBuffer = ByteBuffer.allocate(2);

    public Short decodeNextByte(byte nextByte){
        shortBuffer.put(nextByte);
        if (!shortBuffer.hasRemaining()) {
            shortBuffer.flip();
            Short returnValue = bytesToShort(shortBuffer);
            shortBuffer.clear();
            return returnValue;
        }
        return null;
    }
    private short bytesToShort(ByteBuffer byteArr) {
        short result = (short) ((byteArr.get(0) & 0xff) << 8);
        result += (short) (byteArr.get(1) & 0xff);
        return result;
    }
    public byte[] encode(short num)
    {
        byte[] bytesArr = new byte[2];
        bytesArr[0] = (byte)((num >> 8) & 0xFF);
        bytesArr[1] = (byte)(num & 0xFF);
        return bytesArr;
    }
}
