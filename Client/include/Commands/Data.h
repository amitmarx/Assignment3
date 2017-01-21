#pragma once

#include "Response.h"
#include <vector>
class Data : public Response {
    public:
        short size = 0;
        short blockId = 0;
        char* data;

        Data(short size, short blockId, char * data);

    short getSize();

    short getBlockId();

    char* getData();

    bool isFinalMessage();

    short getOpCode() override;
    ~Data(){
        delete data;
    }
};
