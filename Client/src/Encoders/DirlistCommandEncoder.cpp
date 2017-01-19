//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/DirlistCommandEncoder.h"
#include "../../include/Commands/DirlistRequest.h"

std::vector<char> DirlistCommandEncoder::encode(Command *cmd) {
    DirlistRequest * dirlist = static_cast<DirlistRequest *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(dirlist->getOpCode());
    return opCode;
}
