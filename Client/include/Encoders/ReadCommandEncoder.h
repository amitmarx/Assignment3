//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_READCOMMANDENCODER_H
#define CLIENT_READCOMMANDENCODER_H


#include "../Commands/Command.h"
#include "../EncDec/StringEncoderDecoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include "CommandEncoder.h"

class ReadCommandEncoder:public CommandEncoder {
private:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

public:
    ~ReadCommandEncoder() {
        delete shortEncoderDecoder;
        delete stringEncoderDecoder;
    }

    char* encode(Command *cmd) override;

};


#endif //CLIENT_READCOMMANDENCODER_H
