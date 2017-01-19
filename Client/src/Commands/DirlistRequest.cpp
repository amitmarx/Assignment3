#include "../../include/Commands/DirlistRequest.h"
short DirlistRequest::getOpCode() {
    return opcode::Dirlist;
}
