#include "../../include/Builders/BroadcastCommandBuilder.h"
#include "../../include/Commands/ReadRequest.h"

Command *BroadcastCommandBuilder::decodeNextByte(char nextByte) {
    if (isAdded) {
        std::string fileName = stringEncoderDecoder->decodeNextByte(nextByte);
        if (!fileName.empty()) {
            return new ReadRequest(fileName);
        }
    } else {
        isAdded = nextByte == 1;
    }
    return nullptr;
}
