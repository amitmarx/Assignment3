#pragma once

#include "Command.h"
#include <string>

class DeleteRequest : public Command {
	public:
	std::string fileName;

	std::string getFileName();

	DeleteRequest(const std::string &fileName);

	short getOpCode() override;

};
