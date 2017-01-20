#pragma once

#include <vector>
#include <boost/optional.hpp>
#include "../Commands/Command.h"
#include "../Builders/CommandBuilder.h"
#include "ShortEncoderDecoder.h"
#include "../Builders/CommandBuilderFactory.h"
#include "../Encoders/CommandEncoderFactory.h"

class TFTPEncoderDecoder {

public:
    ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
    CommandBuilderFactory * builderFactory = new CommandBuilderFactory();
    CommandEncoderFactory * commandEncoderFactory = new CommandEncoderFactory();
    CommandBuilder * builder = nullptr;

    ~TFTPEncoderDecoder() {
        delete shortEncoderDecoder;
        delete builderFactory;
        delete commandEncoderFactory;
        delete builder;
    }

    Command *decodeNextByte(char nextByte);

    std::vector<char> encode(Command *message);

};
