#pragma once

#include "Command.h"
#include <string>
	class Broadcast : public Command {
	public:
		bool isAdded_Renamed = false;
		std::string fileName;

		Broadcast(bool isAdded, const std::string &fileName);

		bool isAdded();

		std::string getFileName();

		short getOpCode() override;

	};
