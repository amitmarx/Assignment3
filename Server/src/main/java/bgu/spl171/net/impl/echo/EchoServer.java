package bgu.spl171.net.impl.echo;

import bgu.spl171.net.srv.Server;

public class EchoServer {
    public static void main(String[] args) {

// you can use any server...
//        Server.threadPerClient(
//                7778, //port
//                () ->  new EchoProtocol(), //protocol factory
//                LineMessageEncoderDecoder::new //message encoder decoder factory
//        ).serve();

        Server.reactor(
                Runtime.getRuntime().availableProcessors(),
                7778, //port
                () ->  new EchoProtocol(), //protocol factory
                LineMessageEncoderDecoder::new //message encoder decoder factory
        ).serve();
    }
}
