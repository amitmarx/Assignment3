package bgu.spl171.net.impl.TFTPreactor;

import bgu.spl171.net.impl.TFTP.EncoderDecoders.TFTPEncoderDecoder;
import bgu.spl171.net.impl.TFTP.TFTPLoggedUsers;
import bgu.spl171.net.impl.TFTP.TFTPProtocol;
import bgu.spl171.net.srv.Server;

public class ReactorMain {
    public static void main(String[] args) {
        int port = Integer.parseInt(args[0]);
        TFTPLoggedUsers loggedUsers = new TFTPLoggedUsers();
        Server.reactor(
                Runtime.getRuntime().availableProcessors(),
                port,
                () -> new TFTPProtocol(loggedUsers, "Files"),
                TFTPEncoderDecoder::new
        ).serve();
    }
}
