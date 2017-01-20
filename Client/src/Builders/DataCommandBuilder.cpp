#include "../../include/Builders/DataCommandBuilder.h"
#include "../../include/Commands/Data.h"

Command *DataCommandBuilder::decodeNextByte(char nextByte) {
    if (!size) {
        size = shortEncoderDecoder->decodeNextByte(nextByte);
        if(size){
            int dataSize = size.get();
            data = new char[dataSize];
        }
    } else if (!blockId) {
        blockId = shortEncoderDecoder->decodeNextByte(nextByte);
    } else {
        data[index] = nextByte;
        if (++index >= size.get()) {
            return new Data(size.get(), blockId.get(), data);
        }
    }
    return nullptr;
}

DataCommandBuilder::DataCommandBuilder() {

}
