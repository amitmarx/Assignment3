package bgu.spl171.net.srv.bidi;

import bgu.spl171.net.api.bidi.Connections;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.atomic.AtomicInteger;

public class BidiConnections<T> implements Connections<T> {
    //Change to connection handler
    Map<Integer, ConnectionHandler<T>> connectionList = new ConcurrentHashMap<>();
    AtomicInteger idGenerator = new AtomicInteger();

    @Override
    public boolean send(int connectionId, T msg) {
        ConnectionHandler<T> con = connectionList.get(connectionId);
        if (con == null) return false;

        try {
            con.send(msg);
        } catch (Exception e) {
            return false;
        }
        return true;
    }

    @Override
    public void broadcast(T msg) {
        for (ConnectionHandler<T> connection : connectionList.values()) {
            connection.send(msg);
        }
    }

    @Override
    public void disconnect(int connectionId) {
        connectionList.remove(connectionId);
    }

    public int add(ConnectionHandler<T> handler) {
        int id = idGenerator.incrementAndGet();
        connectionList.put(id, handler);
        return id;
    }

}
