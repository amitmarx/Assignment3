//
// Created by liorgre on 18/01/17.
//

#ifndef CLIENT_COMMANDENCODERFACTORY_H
#define CLIENT_COMMANDENCODERFACTORY_H


#include <bits/unique_ptr.h>
#include "CommandEncoder.h"

class CommandEncoderFactory {
public:
    CommandEncoder * get(short opCode);
    ~CommandEncoderFactory(){};
};


#endif //CLIENT_COMMANDENCODERFACTORY_H
