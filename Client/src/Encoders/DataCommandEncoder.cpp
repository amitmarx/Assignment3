#include "../../include/Encoders/DataCommandEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"
#include "../../include/Commands/Data.h"

char* DataCommandEncoder::encode(Command *cmd) {
    Data *data = static_cast<Data *>(cmd);
    char * opCode = shortEncoderDecoder->encode(data->getOpCode());
    char * size = shortEncoderDecoder->encode(data->getSize());
    char * blockId = shortEncoderDecoder->encode(data->getBlockId());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( std::vector<char>(size,size+2) );
    arrays.push_back( std::vector<char>(blockId,blockId+2) );
    arrays.push_back( std::vector<char>(data->data,data->data+data->size) );

    return EncoderUtils::mergeByteArray(arrays);
}