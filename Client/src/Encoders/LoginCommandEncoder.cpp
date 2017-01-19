//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/LoginCommandEncoder.h"
#include "../../include/Commands/LoginRequest.h"
#include "../../include/Encoders/EncoderUtils.h"

char *LoginCommandEncoder::encode(Command *cmd) {
    LoginRequest * login = static_cast<LoginRequest *>(cmd);
    char * opCode = shortEncoderDecoder->encode(login->getOpCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( stringEncoderDecoder->encodeToVector(login->getUsername()) );
    return EncoderUtils::mergeByteArray(arrays);
}
