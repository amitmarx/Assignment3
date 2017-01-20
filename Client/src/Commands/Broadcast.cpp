#include "../../include/Commands/Broadcast.h"

Broadcast::Broadcast(bool isAdded, const std::string &fileName) {
    this->isAdded_Renamed = isAdded;
    this->fileName = fileName;
}

bool Broadcast::isAdded() {
    return isAdded_Renamed;
}

std::string Broadcast::getFileName() {
    return fileName;
}

short Broadcast::getOpCode() {
    return opcode::Broadcast;
}
