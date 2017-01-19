#pragma once

#include "Command.h"



class DirlistRequest : public Command {
public:
	short getOpCode() override;
};
