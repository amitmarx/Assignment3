//
// Created by liorgre on 18/01/17.
//

#ifndef CLIENT_COMMANDBUILDERFACTORY_H
#define CLIENT_COMMANDBUILDERFACTORY_H


#include "CommandBuilder.h"
#include <memory>
#include <iostream>

class CommandBuilderFactory {
public:
    CommandBuilder * get(short opCode);
    ~CommandBuilderFactory();
};


#endif //CLIENT_COMMANDBUILDERFACTORY_H
