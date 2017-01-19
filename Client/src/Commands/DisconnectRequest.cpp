#include "../../include/Commands/DisconnectRequest.h"

short DisconnectRequest::getOpCode() {
    return opcode::Disconnect;
}
