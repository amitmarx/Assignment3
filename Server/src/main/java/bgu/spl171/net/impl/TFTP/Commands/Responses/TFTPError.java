package bgu.spl171.net.impl.TFTP.Commands.Responses;

public class TFTPError implements Response {
    String errorMsg;
    short errorCode;

    public String getErrorMsg() {
        return errorMsg;
    }

    public short getErrorCode() {
        return errorCode;
    }

    public TFTPError(short errorCode, String errorMsg) {
        this.errorMsg = errorMsg;
        this.errorCode = errorCode;
    }

    public TFTPError(short errorCode) {
        this.errorMsg = errorMessages[errorCode];
        this.errorCode = errorCode;
    }
    public TFTPError(int errorCode){
        this((short)errorCode);
    }

    @Override
    public short getOpCode() {
        return (short) 5;
    }

    public String errorMessage() {
        return errorMsg;
    }

    private static String[] errorMessages = {
            "Not defined, see error message (if any).",
            "File not found",
            "Access violation",
            "Disk full or allocation exceeded",
            "Illegal TFTP operation",
            "File already exists",
            "User not logged in",
            "User already logged in"
    };
}
