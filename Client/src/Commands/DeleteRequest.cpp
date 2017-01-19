#include "../../include/Commands/DeleteRequest.h"

std::string DeleteRequest::getFileName() {
    return fileName;
}

DeleteRequest::DeleteRequest(const std::string &fileName) {
    this->fileName = fileName;
}

short DeleteRequest::getOpCode() {
    return opcode::Delete;
}
