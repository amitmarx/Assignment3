#pragma once

#include "CommandBuilder.h"
#include "../EncDec/StringEncoderDecoder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include <string>
#include <boost/optional.hpp>
class TFTPErrorCommandBuilder : public CommandBuilder {
public:
    boost::optional<short> errorCode = boost::none;
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

    ~TFTPErrorCommandBuilder() {
        delete shortEncoderDecoder;
        delete stringEncoderDecoder;
    }

    Command *decodeNextByte(char nextByte) override;
};
