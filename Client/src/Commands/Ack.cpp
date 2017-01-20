#include "../../include/Commands/Ack.h"

Ack::Ack(short blockId) {
    this->blockId = blockId;
}

Ack::Ack() {
    this->blockId = static_cast<short>(0);
}

short Ack::getBlockId() {
    return blockId;
}

short Ack::getOpCode() {
    return opcode::Ack;
}
