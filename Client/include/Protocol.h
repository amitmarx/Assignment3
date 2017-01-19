//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H


#include "Commands/Command.h"
#include "Commands/Data.h"
#include "EncDec/StringEncoderDecoder.h"
#include "Commands/Ack.h"
#include "Commands/TFTPError.h"
#include "Commands/Broadcast.h"
#include "Commands/ReadRequest.h"
#include "Commands/WriteRequest.h"
#include <string>
#include <queue>

class Protocol {

public:
    Command * process(Command * cmd);
    void notifySentCommand(Command * cmd);
    bool shouldTerminate();
private:
    StringEncoderDecoder * stringEncoderDecoder = new StringEncoderDecoder();
    std::string fileToWrite;
    std::string dirlist;
    bool didAskToTerminate = false;
    bool canTerminate = false;
    std::queue<Data *> dataToSend;

    Command * handleData(Data *data);

    Command * handleAck(Ack *pAck);

    Command *  handleError(TFTPError *pError);

    Command *  handleBroadcast(Broadcast *pBroadcast);

    void notifyRead(ReadRequest *pRequest);

    void notifyWrite(WriteRequest *pRequest);

    void notifyError();

    void resetState();

    void notifyDisconnect();

    void writeToFile(char *data, short size, std::string fileName);
};


#endif //CLIENT_PROTOCOL_H
