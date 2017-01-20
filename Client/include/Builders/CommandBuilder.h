#pragma once


#include "../Commands/Command.h"
class CommandBuilder {
public:
    virtual Command *decodeNextByte(char nextByte) = 0;
    CommandBuilder(){}
    ~CommandBuilder(){}
};
