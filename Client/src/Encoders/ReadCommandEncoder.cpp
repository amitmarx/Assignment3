//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/ReadCommandEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"
#include "../../include/Commands/ReadRequest.h"

char *ReadCommandEncoder::encode(Command *cmd) {
    ReadRequest * request = static_cast<ReadRequest *>(cmd);
    char * opCode = shortEncoderDecoder->encode(request->getOpCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( stringEncoderDecoder->encodeToVector(request->getFileName()) );
    return EncoderUtils::mergeByteArray(arrays);
}