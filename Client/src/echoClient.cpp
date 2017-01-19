#include <stdlib.h>
#include "../include/connectionHandler.h"
#include "../include/Commands/DirlistRequest.h"
#include "../include/Commands/LoginRequest.h"
#include "../include/Commands/DisconnectRequest.h"
#include "../include/Commands/DeleteRequest.h"
#include <boost/thread.hpp>
#include <boost/tokenizer.hpp>

std::vector<std::string> splitString(std::string basic_string, char i);

Command *getCommandFromString(std::string basic_string);

using boost::thread;

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    TFTPEncoderDecoder * encDec = new TFTPEncoderDecoder();
    Protocol * protocol = new Protocol();
    ConnectionHandler connectionHandler(host, port,encDec,protocol);;
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    boost::thread listener (boost::bind(&ConnectionHandler::startListen, &connectionHandler));
	
	//From here we will see the rest of the ehco client implementation:
    while (!protocol->shouldTerminate()) {
        std::string input;
        std::getline(std::cin,input);

        Command * cmd = getCommandFromString(input);
        connectionHandler.sendCommand(cmd);
    }
    return 0;
}

Command *getCommandFromString(std::string input) {
    std::vector<std::string> splittedInput = splitString(input, ' ');
    std::string code = splittedInput[0];
    if(code=="RRQ"){
        return new ReadRequest(splittedInput[1]);
    }
    if(code=="WRQ"){
        return new WriteRequest(splittedInput[1]);
    }
    if(code=="DIRQ"){
        return new DirlistRequest();
    }
    if(code=="LOGRQ"){
        return new LoginRequest(splittedInput[1]);
    }
    if(code=="DELRQ"){
        return new DeleteRequest(splittedInput[1]);
    }
    if(code=="DISC"){
        return new DisconnectRequest();
    }
    return nullptr;
}

std::vector<std::string> splitString(std::string str, char delimiter) {
    int startPos=0;
    std::vector<std::string> returnValue;
    for(int i=0; i<str.size();i++) {
        if(str[i]==delimiter){
            returnValue.push_back(str.substr(startPos,i-startPos));
            startPos=i+1;
        }
    }
    returnValue.push_back(str.substr(startPos));
    return returnValue;
}

