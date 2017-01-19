//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/DisconnectCommandEncoder.h"
#include "../../include/Commands/DisconnectRequest.h"

char *DisconnectCommandEncoder::encode(Command *cmd) {
    DisconnectRequest * diconnect = static_cast<DisconnectRequest *>(cmd);
    char * opCode = shortEncoderDecoder->encode(diconnect->getOpCode());
    return opCode;
}