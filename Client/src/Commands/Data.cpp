#include "../../include/Commands/Data.h"

Data::Data(short size, short blockId, char * data) {
    this->size = size;
    this->blockId = blockId;
    this->data = data;
}

short Data::getSize() {
    return size;
}

short Data::getBlockId() {
    return blockId;
}

char* Data::getData() {
    return data;
}

bool Data::isFinalMessage() {
    return size < 512;
}

short Data::getOpCode() {
    return opcode::Data;
}
