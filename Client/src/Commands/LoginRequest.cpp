#include "../../include/Commands/LoginRequest.h"


std::string LoginRequest::getUsername() {
    return username;
}

LoginRequest::LoginRequest(const std::string &username) {
    this->username = username;
}

short LoginRequest::getOpCode() {
    return opcode::Login;
}

