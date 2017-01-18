#pragma once

#include <vector>

namespace bgu
{
	namespace spl171
	{
		namespace net
		{
			namespace impl
			{
				namespace TFTP
				{
					namespace CommandEncoders
					{

						using bgu::spl171::net::impl::TFTP::Commands::Command;

						class CommandEncoder
						{
						public:
							virtual std::vector<char> encode(Command *cmd) = 0;
//JAVA TO C++ CONVERTER TODO TASK: There is no equivalent in C++ to Java static interface methods:
//							static CommandEncoder get(short opCode)
						//	{
						//		switch (opCode)
						//		{
						//			case 3:
						//				return new DataCommandEncoder();
						//			case 4:
						//				return new AckCommandEncoder();
						//			case 5:
						//				return new TFTPErrorEncoder();
						//			case 9:
						//				return new BroadcastCommandEncoder();
						//		}
						//		//Todo make an error
						//		return nullptr;
						//	}
						};

					}
				}
			}
		}
	}
}
