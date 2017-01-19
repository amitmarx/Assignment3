//
// Created by liorgre on 19/01/17.
//

#ifndef CLIENT_DELETECOMMANDENCODER_H
#define CLIENT_DELETECOMMANDENCODER_H


#include "CommandEncoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include "../EncDec/StringEncoderDecoder.h"

class DeleteCommandEncoder : public CommandEncoder {
private:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

public:
    ~DeleteCommandEncoder() {
        delete shortEncoderDecoder;
        delete stringEncoderDecoder;
    }

    std::vector<char> encode(Command *cmd) override;

};


#endif //CLIENT_DELETECOMMANDENCODER_H
