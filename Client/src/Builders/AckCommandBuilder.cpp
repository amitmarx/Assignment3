#include "../../include/Builders/AckCommandBuilder.h"
#include "../../include/Commands/Ack.h"

Command *AckCommandBuilder::decodeNextByte(char nextByte) {
    boost::optional<short> blockId = shortEncoderDecoder->decodeNextByte(nextByte);
    if (blockId != boost::none) {
        return new Ack(blockId.get());
    }
    return nullptr;
}
