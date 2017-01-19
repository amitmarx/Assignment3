//
// Created by liorgre on 18/01/17.
//

#include "../../include/Builders/CommandBuilderFactory.h"
#include "../../include/Builders/DataCommandBuilder.h"
#include "../../include/Builders/TFTPErrorCommandBuilder.h"
#include "../../include/Builders/AckCommandBuilder.h"
#include "../../include/Builders/BroadcastCommandBuilder.h"

CommandBuilder* CommandBuilderFactory::get(short opCode) {
    		switch (opCode)
    		{
				case 3:
    				return new DataCommandBuilder();
    			case 5:
    				return new TFTPErrorCommandBuilder();
    			case 4:
    				return new AckCommandBuilder();
    			case 9:
    				return new BroadcastCommandBuilder();
    		}
    return nullptr;
}

CommandBuilderFactory::~CommandBuilderFactory() {

}
