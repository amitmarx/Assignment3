#pragma once

#include "CommandEncoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include <vector>


class DataCommandEncoder : public CommandEncoder {

private:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
public:
    ~DataCommandEncoder() {
        delete shortEncoderDecoder;
    }

    char * encode(Command *cmd) override;
};
