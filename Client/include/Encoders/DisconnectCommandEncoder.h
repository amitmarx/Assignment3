//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_DISCONNECTCOMMANDENCODER_H
#define CLIENT_DISCONNECTCOMMANDENCODER_H


#include "../../include/Encoders/CommandEncoder.h"
#include "../../include/EncDec/ShortEncoderDecoder.h"

class DisconnectCommandEncoder : public CommandEncoder {
public:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();

    ~DisconnectCommandEncoder() {
        delete shortEncoderDecoder;
    }

    std::vector<char> encode(Command *cmd) override;
};


#endif //CLIENT_DISCONNECTCOMMANDENCODER_H
