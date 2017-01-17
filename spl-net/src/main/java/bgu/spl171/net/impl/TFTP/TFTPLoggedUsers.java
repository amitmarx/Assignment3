package bgu.spl171.net.impl.TFTP;

import java.util.HashSet;
import java.util.Set;

public class TFTPLoggedUsers {
    Set<String> loggedInUsers = new HashSet<>();

    public synchronized boolean add(String username){
        return loggedInUsers.add(username);
    }

    public synchronized void remove(String username){
        loggedInUsers.remove(username);
    }
}
