//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/ReadCommandEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"
#include "../../include/Commands/ReadRequest.h"

std::vector<char> ReadCommandEncoder::encode(Command *cmd) {
    ReadRequest * request = static_cast<ReadRequest *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(request->getOpCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back(opCode );
    arrays.push_back( stringEncoderDecoder->encode(request->getFileName()) );
    return EncoderUtils::mergeByteArray(arrays);
}