//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/WriteCommandEncoder.h"
#include "../../include/Commands/WriteRequest.h"
#include "../../include/Encoders/EncoderUtils.h"

std::vector<char> WriteCommandEncoder::encode(Command *cmd) {
    WriteRequest * request = static_cast<WriteRequest *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(request->getOpCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( opCode );
    arrays.push_back( stringEncoderDecoder->encode(request->getFileName()) );
    return EncoderUtils::mergeByteArray(arrays);
}