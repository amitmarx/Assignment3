#include "../../include/Commands/ReadRequest.h"

ReadRequest::ReadRequest(const std::string &fileName) {
    this->fileName = fileName;
}

std::string ReadRequest::getFileName() {
    return fileName;
}

short ReadRequest::getOpCode() {
    return opcode::ReadRequest;
}

