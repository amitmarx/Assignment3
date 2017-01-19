//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/WriteCommandEncoder.h"
#include "../../include/Commands/WriteRequest.h"
#include "../../include/Encoders/EncoderUtils.h"

char *WriteCommandEncoder::encode(Command *cmd) {
    WriteRequest * request = static_cast<WriteRequest *>(cmd);
    char * opCode = shortEncoderDecoder->encode(request->getOpCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( stringEncoderDecoder->encodeToVector(request->getFileName()) );
    return EncoderUtils::mergeByteArray(arrays);
}