#pragma once

#include <vector>
#include "../Commands/Command.h"

class CommandEncoder {
public:
    virtual std::vector<char> encode(Command *cmd) = 0;

};
