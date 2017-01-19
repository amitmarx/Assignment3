#include <boost/optional.hpp>
#include "../../include/EncDec/ShortEncoderDecoder.h"


boost::optional<short> ShortEncoderDecoder::decodeNextByte(char nextByte) {
    shortBuffer[index] = nextByte;
    if(index==1){
        boost::optional<short> returnValue(bytesToShort(shortBuffer));
        index=0;
        return returnValue;
    }
    index++;
    return boost::none;
}

char * ShortEncoderDecoder::encode(short num)
{
    char * shortPtr =new char[2];
    shortPtr[0] = ((num >> 8) & 0xFF);
    shortPtr[1] = (num & 0xFF);
    return shortPtr;
}
short ShortEncoderDecoder::bytesToShort(char* bytesArr)
{
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}