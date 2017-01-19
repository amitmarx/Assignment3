#pragma once

#include "Command.h"
#include <string>


class ReadRequest : public Command {

public:
    std::string fileName;

    ReadRequest(const std::string &fileName);

    std::string getFileName();

    short getOpCode() override;

};
