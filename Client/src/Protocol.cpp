//
// Created by liorgre on 19/01/17.
//

#include <iostream>
#include <fstream>
#include "../include/Protocol.h"

Command * Protocol::process(Command *cmd) {
    switch (cmd->getOpCode())
    {
        case 3:
            return handleData(static_cast<Data *>(cmd));
        case 4:
            return handleAck(static_cast<Ack *>(cmd));
        case 5:
            return handleError(static_cast<TFTPError *>(cmd));
        case 9:
            return handleBroadcast(static_cast<Broadcast *>(cmd));
    }
    return nullptr;
}

void Protocol::notifySentCommand(Command *cmd) {
    switch (cmd->getOpCode())
    {
        case 1:
            notifyRead(static_cast<ReadRequest *>(cmd));
            break;
        case 2:
            notifyWrite(static_cast<WriteRequest *>(cmd));
            break;
        case 5:
            notifyError();
            break;
        case 10:
            notifyDisconnect();
            break;
    }
}

Command * Protocol::handleData(Data *data) {
    if(!fileToRead.empty()){
        writeToFile(data->data,data->size,fileToRead);
        if(data->isFinalMessage()){
            std::cout<<"RRQ "<<fileToRead<<" complete"<<std::endl;
            fileToRead.clear();
        }
    }
    else{
        for(int i=0;i<data->size;i++) {
            std::string decoded = stringEncoderDecoder->decodeNextByte(data->data[i]);
            if(!decoded.empty()){
                dirlist += decoded + "\n";
            }
        }
        if(data->isFinalMessage()){
            std::cout<<dirlist<<std::endl;
            dirlist.clear();
        }
    }
    return new Ack(data->blockId);
}

Command * Protocol::handleAck(Ack *pAck) {
    std::cout<<"ACK "<<pAck->blockId<<std::endl;
    if(!dataToSend.empty()) {
        Command *returnVal = dataToSend.front();
        dataToSend.pop();
        return returnVal;
    }
    if(numberOfBlocks-1==pAck->blockId){
        std::cout<<"WRQ "<<fileToWrite<< " complete"<<std::endl;
        fileToWrite.clear();
        numberOfBlocks =0;
    }
    if(didAskToTerminate){
        canTerminate = true;
    }
    return nullptr;
}

bool Protocol::shouldTerminate() {
    return canTerminate;
}

Command * Protocol::handleError(TFTPError *pError) {
    std::cout<<"Error "<<pError->getErrorCode()<<std::endl;
    resetState();
    return nullptr;
}

void Protocol::resetState(){
    fileToRead.clear();
    dirlist.clear();
    while (!dataToSend.empty()){
        Data* tmp = dataToSend.front();
        dataToSend.pop();
        delete tmp;
    }
}

Command *  Protocol::handleBroadcast(Broadcast *pBroadcast) {
    std::string isAdded;
    if(pBroadcast->isAdded()){
        isAdded = "add";
    } else{
        isAdded = "del";
    }
    std::cout<<"BCAST "<<isAdded+" "<< pBroadcast->getFileName() <<std::endl;
    return nullptr;
}

void Protocol::notifyRead(ReadRequest *pRequest) {
    fileToRead = pRequest->getFileName();
}

void Protocol::notifyWrite(WriteRequest *pRequest) {
    std::ifstream file(pRequest->getFileName());
    file.seekg(0,std::ios::end);
    size_t len =file.tellg();
    char * ret = new char[len];
    file.seekg((0,std::ios::beg));
    file.read(ret,len);
    file.close();

    int blocks = len/512;
    for(int block=0; block<blocks;block++){
        char* data = new char[512];
        std::copy(ret+ block*512, ret+(block+1)*512,data);
        dataToSend.push(new Data(512,block,data));
    }
    int modulo = len%512;
    char * data =new char[modulo];
    int startPos = blocks*512;
    std::copy(ret+startPos,ret+startPos+modulo,data);
    dataToSend.push((new Data(modulo,blocks,data)));
    numberOfBlocks = dataToSend.size();
    fileToWrite = pRequest->getFileName();
    delete ret;
}

void Protocol::notifyError() {
    resetState();
}

void Protocol::notifyDisconnect() {
    didAskToTerminate= true;
}

void Protocol::writeToFile(char *data, short size, std::string fileName) {
    std::ofstream out;
    out.open(fileName,std::ios_base::app);
    if(!out){
        return;;
    }
    out.write(data,size);
    out.close();
}
