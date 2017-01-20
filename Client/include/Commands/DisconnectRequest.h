#pragma once

#include "Command.h"


class DisconnectRequest : public Command {

public:
    short getOpCode() override;
};

