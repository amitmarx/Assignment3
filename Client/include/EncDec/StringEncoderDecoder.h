#pragma once

#include <string>
#include <vector>


class StringEncoderDecoder {
public:
    std::vector<char> stringBuffer;
    std::string decodeNextByte(char nextByte);

private:
    std::string getString();

public:
    std::vector<char> encode(const std::string &str);

};
