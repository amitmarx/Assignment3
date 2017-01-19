//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/DeleteCommandEncoder.h"
#include "../../include/Commands/DeleteRequest.h"
#include "../../include/Encoders/EncoderUtils.h"

std::vector<char> DeleteCommandEncoder::encode(Command *cmd) {
    DeleteRequest * deleteReq = static_cast<DeleteRequest *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(deleteReq->getOpCode());
    std::vector<char> fileName = stringEncoderDecoder->encode(deleteReq->getFileName());
    std::vector<std::vector<char>> arrays;
    arrays.push_back(opCode );
    arrays.push_back( fileName );
    return EncoderUtils::mergeByteArray(arrays);

}
