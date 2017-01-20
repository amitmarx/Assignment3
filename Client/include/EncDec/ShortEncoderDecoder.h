#pragma once

#include <vector>
#include <boost/optional.hpp>


class ShortEncoderDecoder {
private:
    int index =0;
    char shortBuffer [2];

public:
    ~ShortEncoderDecoder() {}

    boost::optional<short> decodeNextByte(char nextByte);
    std::vector<char> encode(short num);

private:
    short bytesToShort(char* byteArr);


};
