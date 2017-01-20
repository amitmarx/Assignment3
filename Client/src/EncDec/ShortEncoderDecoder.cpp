#include <boost/optional.hpp>
#include "../../include/EncDec/ShortEncoderDecoder.h"


boost::optional<short> ShortEncoderDecoder::decodeNextByte(char nextByte) {
    shortBuffer[index] = nextByte;
    index++;
    if(index==2){
        boost::optional<short> returnValue(bytesToShort(shortBuffer));
        index=0;
        return returnValue;
    }
    return boost::none;
}

std::vector<char> ShortEncoderDecoder::encode(short num)
{
    std::vector<char> shortInBytes;
    shortInBytes.push_back((num >> 8) & 0xFF);
    shortInBytes.push_back(num & 0xFF);
    return shortInBytes;
}
short ShortEncoderDecoder::bytesToShort(char* bytesArr)
{
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}