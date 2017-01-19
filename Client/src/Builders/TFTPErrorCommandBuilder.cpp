#include "../../include/Builders/TFTPErrorCommandBuilder.h"
#include "../../include/Commands/TFTPError.h"

Command *TFTPErrorCommandBuilder::decodeNextByte(char nextByte) {
    if (!errorCode) {
        errorCode = shortEncoderDecoder->decodeNextByte(nextByte);
    } else {
        std::string errorMsg = stringEncoderDecoder->decodeNextByte(nextByte);
        if (!errorMsg.empty()) {
            return new TFTPError(errorCode.get(), errorMsg);
        }
    }
    return nullptr;
}
