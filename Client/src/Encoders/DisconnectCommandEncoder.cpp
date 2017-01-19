//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/DisconnectCommandEncoder.h"
#include "../../include/Commands/DisconnectRequest.h"

std::vector<char> DisconnectCommandEncoder::encode(Command *cmd) {
    DisconnectRequest * disconnect = static_cast<DisconnectRequest *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(disconnect->getOpCode());
    return opCode;
}