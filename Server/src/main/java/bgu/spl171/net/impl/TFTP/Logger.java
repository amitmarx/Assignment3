package bgu.spl171.net.impl.TFTP;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Logger {
    private static boolean isEnable=true;
    private static DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");

    public static void log(String msg) {
        if (isEnable) {
            LocalDateTime now = LocalDateTime.now();
            System.out.println(dtf.format(now)+"   "+ msg);
        }
    }
}
