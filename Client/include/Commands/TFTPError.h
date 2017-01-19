#pragma once

#include "Response.h"
#include <string>
#include <vector>


class TFTPError : public Response {
public:
    std::string errorMsg;
    short errorCode = 0;

    std::string getErrorMsg();

    short getErrorCode();

    TFTPError(short errorCode, const std::string &errorMsg);

    short getOpCode() override;

    std::string getErrorMessage();
};
