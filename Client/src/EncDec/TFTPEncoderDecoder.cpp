#include "../../include/EncDec/TFTPEncoderDecoder.h"

Command *TFTPEncoderDecoder::decodeNextByte(char nextByte) {
    Command *returnValue = nullptr;

    if (builder == nullptr) {
        boost::optional<short> opCode = shortEncoderDecoder->decodeNextByte(nextByte);
        if (opCode != boost::none) {
            builder = builderFactory->get(opCode.get());
        }
    } else {
        returnValue = builder->decodeNextByte(nextByte);
        if (returnValue != nullptr) {
            builder = nullptr;
        }
    }
    return returnValue;
}

char * TFTPEncoderDecoder::encode(Command *message) {
    return commandEncoderFactory->get(message->getOpCode())->encode(message);
}
