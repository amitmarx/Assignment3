//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/DeleteCommandEncoder.h"
#include "../../include/Commands/DeleteRequest.h"
#include "../../include/Encoders/EncoderUtils.h"

char *DeleteCommandEncoder::encode(Command *cmd) {
    DeleteRequest * deleteReq = static_cast<DeleteRequest *>(cmd);
    char * opCode = shortEncoderDecoder->encode(deleteReq->getOpCode());
    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( std::vector<char>(deleteReq->getFileName().begin(),deleteReq->getFileName().end()+1) );
    return EncoderUtils::mergeByteArray(arrays);

}
