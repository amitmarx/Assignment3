package bgu.spl171.net.impl.TFTP.Commands;

import bgu.spl171.net.impl.TFTP.Commands.Responses.Response;

public class LoginRequest implements Command {
    String username;

    public String getUsername() {
        return username;
    }

    public LoginRequest(String username) {
        this.username = username;
    }

    @Override
    public short getOpCode() {
        return OpCode.Login.getValue();
    }

}
