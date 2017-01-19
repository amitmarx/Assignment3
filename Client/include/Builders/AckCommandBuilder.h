#pragma once

#include "CommandBuilder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include "../Commands/Command.h"
#include <boost/optional.hpp>

class AckCommandBuilder : public CommandBuilder {
public:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();

    ~AckCommandBuilder() {
        delete shortEncoderDecoder;
    }

    Command *decodeNextByte(char nextByte) override;
};
