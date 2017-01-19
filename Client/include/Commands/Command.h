#pragma once

class Command {
	public:
		virtual short getOpCode() = 0;

	};
namespace opcode{
enum OpCode : short
	{
		ReadRequest=1,
		WriteRequest=2,
		Data=3,
		Ack=4,
		Error=5,
		Dirlist=6,
		Login=7,
		Delete=8,
		Broadcast=9,
		Disconnect=10
	};

}