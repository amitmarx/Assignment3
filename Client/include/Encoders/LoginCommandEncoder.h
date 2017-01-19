//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_LOGINCOMMANDENCODER_H
#define CLIENT_LOGINCOMMANDENCODER_H


#include "CommandEncoder.h"
#include "../EncDec/StringEncoderDecoder.h"
#include "../EncDec/ShortEncoderDecoder.h"

class LoginCommandEncoder : public CommandEncoder {
private:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

public:
    ~LoginCommandEncoder() {
        delete shortEncoderDecoder;
        delete stringEncoderDecoder;
    }

    char* encode(Command *cmd) override;

};


#endif //CLIENT_LOGINCOMMANDENCODER_H
