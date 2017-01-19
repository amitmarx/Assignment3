#pragma once

#include "Command.h"
#include <string>


class WriteRequest : public Command {

public:
    std::string fileName;

    WriteRequest(const std::string &fileName);

    std::string getFileName();

    short getOpCode() override;

};