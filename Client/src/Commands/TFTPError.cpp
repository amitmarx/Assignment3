#include "../../include/Commands/TFTPError.h"

short TFTPError::getErrorCode() {
    return errorCode;
}

TFTPError::TFTPError(short errorCode, const std::string &errorMsg) {
    this->errorMsg = errorMsg;
    this->errorCode = errorCode;
}

short TFTPError::getOpCode() {
    return static_cast<short>(5);
}

std::string TFTPError::getErrorMessage() {
    return errorMsg;
}
