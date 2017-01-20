#pragma once

#include "Command.h"
#include <string>

class LoginRequest : public Command {
public:
    std::string username;

    std::string getUsername();

    LoginRequest(const std::string &username);

    short getOpCode() override;

};