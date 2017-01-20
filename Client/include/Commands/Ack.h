#pragma once

#include "Response.h"
class Ack : public Response {
public:
	short blockId = 0;

	Ack(short blockId);

	Ack();

	short getBlockId();

	short getOpCode() override;

};
