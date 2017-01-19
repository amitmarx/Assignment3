#include "../../include/Encoders/DataCommandEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"
#include "../../include/Commands/Data.h"

std::vector<char> DataCommandEncoder::encode(Command *cmd) {
    Data *data = static_cast<Data *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(data->getOpCode());
    std::vector<char> size = shortEncoderDecoder->encode(data->getSize());
    std::vector<char> blockId = shortEncoderDecoder->encode(data->getBlockId());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( opCode );
    arrays.push_back( size );
    arrays.push_back( blockId );
    arrays.push_back( std::vector<char>(data->data,data->data+data->size) );

    return EncoderUtils::mergeByteArray(arrays);
}