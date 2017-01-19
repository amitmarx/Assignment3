#include "../../include/EncDec/StringEncoderDecoder.h"
#include "../../include/Encoders/EncoderUtils.h"

std::string StringEncoderDecoder::decodeNextByte(char nextByte) {
    std::string returnValue;
    if (nextByte == 0) {
        returnValue = getString();
        stringBuffer.clear();
        return returnValue;
    }
    stringBuffer.push_back(nextByte);
    return std::string();
}

std::string StringEncoderDecoder::getString() {
    return std::string(stringBuffer.begin(),stringBuffer.end()) ;
}

std::vector<char> StringEncoderDecoder::encode(const std::string &str) {
    std::vector<char> bytes(str.begin(),str.end()+1);
    return bytes;
}
