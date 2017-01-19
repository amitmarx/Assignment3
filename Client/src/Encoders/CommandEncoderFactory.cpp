//
// Created by liorgre on 18/01/17.
//

#include "../../include/Encoders/TFTPErrorEncoder.h"
#include "../../include/Encoders/DataCommandEncoder.h"
#include "../../include/Encoders/AckCommandEncoder.h"
#include "../../include/Encoders/CommandEncoderFactory.h"
#include "../../include/Encoders/DirlistCommandEncoder.h"
#include "../../include/Encoders/LoginCommandEncoder.h"
#include "../../include/Encoders/DeleteCommandEncoder.h"

CommandEncoder * CommandEncoderFactory::get(short opCode) {
		switch (opCode)
		{
//			case 1:
//				return new ReadCommandEncoder();
//			case 2:
//				return new WriteCommandEncoder();
			case 3:
				return new DataCommandEncoder();
			case 4:
				return new AckCommandEncoder();
			case 5:
				return new TFTPErrorEncoder();
			case 6:
				return new DirlistCommandEncoder();
			case 7:
				return new LoginCommandEncoder();
			case 8:
				return new DeleteCommandEncoder();
//			case 10:
//				return new DisconnectCommandEncoder();
		}

		return nullptr;
	}
