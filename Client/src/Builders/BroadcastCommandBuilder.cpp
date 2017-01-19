#include "../../include/Builders/BroadcastCommandBuilder.h"
#include "../../include/Commands/ReadRequest.h"
#include "../../include/Commands/Broadcast.h"

Command *BroadcastCommandBuilder::decodeNextByte(char nextByte) {
    if (isAdded) {
        std::string fileName = stringEncoderDecoder->decodeNextByte(nextByte);
        if (!fileName.empty()) {
            return new Broadcast(isAdded.get(), fileName);
        }
    } else {
        isAdded = nextByte == 1;
    }
    return nullptr;
}
