#pragma once

#include "CommandEncoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include <vector>


class AckCommandEncoder : public CommandEncoder {
public:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();

    ~AckCommandEncoder() {
        delete shortEncoderDecoder;
    }

    std::vector<char> encode(Command *cmd) override;
};
