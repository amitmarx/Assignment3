#include "../../include/Encoders/TFTPErrorEncoder.h"
#include "../../include/Encoders/EncoderUtils.h"
#include "../../include/Commands/TFTPError.h"

std::vector<char> TFTPErrorEncoder::encode(Command *cmd) {
    TFTPError *error = static_cast<TFTPError *>(cmd);
    std::vector<char> opCode = shortEncoderDecoder->encode(error->getOpCode());
    std::vector<char> errorCode = shortEncoderDecoder->encode(error->getErrorCode());

    std::vector<std::vector<char>> arrays;
    arrays.push_back( opCode );
    arrays.push_back( errorCode );
    arrays.push_back( stringEncoderDecoder->encode(error->getErrorMessage()));

    return EncoderUtils::mergeByteArray(arrays);
}
