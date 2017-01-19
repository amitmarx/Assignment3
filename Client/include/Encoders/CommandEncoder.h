#pragma once

#include <vector>
#include "../Commands/Command.h"

class CommandEncoder {
public:
    virtual char * encode(Command *cmd) = 0;

};
