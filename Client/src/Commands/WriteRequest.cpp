#include "../../include/Commands/WriteRequest.h"

WriteRequest::WriteRequest(const std::string &fileName) {
    this->fileName = fileName;
}

std::string WriteRequest::getFileName() {
    return fileName;
}

short WriteRequest::getOpCode() {
    return opcode::WriteRequest;
}