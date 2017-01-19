#pragma once

#include <string>
#include <vector>


class StringEncoderDecoder {
public:
    std::vector<char> stringBuffer;
    std::vector<char> encodeToVector(const std::string &str);
    std::string decodeNextByte(char nextByte);

private:
    std::string getString();

public:
    char * encode(const std::string &str);

};
