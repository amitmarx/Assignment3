//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_WRITECOMMANDENCODER_H
#define CLIENT_WRITECOMMANDENCODER_H


#include "../Commands/Command.h"
#include "../EncDec/StringEncoderDecoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include "CommandEncoder.h"

class WriteCommandEncoder: public CommandEncoder {
private:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

public:
    ~WriteCommandEncoder() {
        delete shortEncoderDecoder;
        delete stringEncoderDecoder;
    }

    std::vector<char> encode(Command *cmd) override;

};


#endif //CLIENT_WRITECOMMANDENCODER_H
