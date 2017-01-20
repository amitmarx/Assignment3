

#include "../../include/Commands/Ack.h"
#include "../../include/Encoders/AckCommandEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"

std::vector<char> AckCommandEncoder::encode(Command *cmd) {
    Ack * ack = static_cast<Ack *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(static_cast<short>(4));
    std::vector<char> blockId =shortEncoderDecoder->encode(ack->getBlockId());
    std::vector<std::vector<char>> arrays;
    arrays.push_back(opCode );
    arrays.push_back(blockId);
    return EncoderUtils::mergeByteArray(arrays);
}

