//
// Created by liorgre on 19/01/17.
//

#include "../../include/Encoders/LoginCommandEncoder.h"
#include "../../include/Commands/LoginRequest.h"
#include "../../include/Encoders/EncoderUtils.h"

std::vector<char> LoginCommandEncoder::encode(Command *cmd) {
    LoginRequest * login = static_cast<LoginRequest *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(login->getOpCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( opCode );
    arrays.push_back( stringEncoderDecoder->encode(login->getUsername()) );
    return EncoderUtils::mergeByteArray(arrays);
}
