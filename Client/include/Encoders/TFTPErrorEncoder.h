#pragma once

#include "CommandEncoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include "../EncDec/StringEncoderDecoder.h"
#include "../Commands/Command.h"
#include <vector>

class TFTPErrorEncoder : public CommandEncoder {
private:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

public:
    ~TFTPErrorEncoder() {
        delete shortEncoderDecoder;
        delete stringEncoderDecoder;
    }

    char* encode(Command *cmd) override;
};
