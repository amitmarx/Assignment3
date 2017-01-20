#pragma once

#include "CommandBuilder.h"
#include "../EncDec/StringEncoderDecoder.h"
#include "../Commands/Command.h"
#include <string>
#include <boost/optional.hpp>

class BroadcastCommandBuilder : public CommandBuilder {
public:
    boost::optional<bool> isAdded = boost::none;
    StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

    ~BroadcastCommandBuilder() {
        delete stringEncoderDecoder;
    }

    Command *decodeNextByte(char nextByte) override;
};
