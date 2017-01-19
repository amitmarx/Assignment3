#include "../../include/Encoders/TFTPErrorEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"
#include "../../include/Commands/TFTPError.h"

char * TFTPErrorEncoder::encode(Command *cmd) {
    TFTPError *error = static_cast<TFTPError *>(cmd);
    char * opCode = shortEncoderDecoder->encode(error->getOpCode());
    char * errorCode = shortEncoderDecoder->encode(error->getErrorCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( std::vector<char>(opCode,opCode+2) );
    arrays.push_back( std::vector<char>(errorCode,errorCode+2) );
    arrays.push_back( std::vector<char>(stringEncoderDecoder->encodeToVector(error->getErrorMessage())) );

    return EncoderUtils::mergeByteArray(arrays);
}
