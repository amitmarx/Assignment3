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
            delete builder;
            builder = nullptr;
        }
    }
    return returnValue;
}

std::vector<char> TFTPEncoderDecoder::encode(Command *message) {
    CommandEncoder * encoder = commandEncoderFactory->get(message->getOpCode());
    std::vector<char> returnVal = encoder -> encode(message);
    delete encoder;
    return returnVal;
}
