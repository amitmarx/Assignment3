package bgu.spl171.net.impl.TFTP.CommandEncoders;

public class EncoderUtils {

    static byte[] mergeByteArray(byte[]... arrays) {
        int size = 0;
        for (byte[] array : arrays) {
            size+=array.length;
        }
        byte[] result = new byte[size];

        int index=0;
        for (byte[] array : arrays) {
            System.arraycopy(array, 0, result, index, array.length);
            index+=array.length;
        }
        return result;
    }
}
