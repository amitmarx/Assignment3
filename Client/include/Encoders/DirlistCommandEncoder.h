//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_DIRLISTCOMMANDENCODER_H
#define CLIENT_DIRLISTCOMMANDENCODER_H


#include "CommandEncoder.h"
#include "../EncDec/ShortEncoderDecoder.h"

class DirlistCommandEncoder : public CommandEncoder {
public:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();

    ~DirlistCommandEncoder() {
        delete shortEncoderDecoder;
    }

    char * encode(Command *cmd) override;
};


#endif //CLIENT_DIRLISTCOMMANDENCODER_H
