#pragma once

#include "CommandBuilder.h"
#include "../EncDec/ShortEncoderDecoder.h"
#include <vector>
#include <boost/optional.hpp>
class DataCommandBuilder : public CommandBuilder {
public:
    boost::optional<short> size = boost::none;
    boost::optional<short> blockId = boost::none;
private:
    char * data;
    int index = 0;
    ShortEncoderDecoder *const shortEncoderDecoder = new ShortEncoderDecoder();

public:
    DataCommandBuilder();
    ~DataCommandBuilder() {
        delete shortEncoderDecoder;
    }

    Command *decodeNextByte(char nextByte) override;
};
