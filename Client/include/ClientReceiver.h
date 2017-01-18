//
// Created by Amit Marx on 18/01/2017.
//

#ifndef CLIENT_CLIENTRECEIVER_H
#define CLIENT_CLIENTRECEIVER_H


#include "connectionHandler.h"

class ClientReceiver {
private:
    ConnectionHandler & handler;
public:
    ClientReceiver(ConnectionHandler & handler);
    void receiverMessages();
};


#endif //CLIENT_CLIENTRECIEVER_H
