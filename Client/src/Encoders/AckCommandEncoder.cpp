

#include "../../include/Commands/Ack.h"
#include "../../include/Encoders/AckCommandEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"

char * AckCommandEncoder::encode(Command *cmd) {
    Ack * ack = static_cast<Ack *>(cmd);
    char * opCode = shortEncoderDecoder->encode(static_cast<short>(4));
    char * blockId =shortEncoderDecoder->encode(ack->getBlockId());
    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( std::vector<char>(blockId,blockId+2) );
    return EncoderUtils::mergeByteArray(arrays);
}

