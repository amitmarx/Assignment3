#pragma once

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
					namespace CommandBuilders
					{

						using bgu::spl171::net::impl::TFTP::Commands::Command;

						class CommandBuilder
						{
						public:
							virtual Command *decodeNextByte(char nextByte) = 0;
//JAVA TO C++ CONVERTER TODO TASK: There is no equivalent in C++ to Java static interface methods:
//							static CommandBuilder createBuilder(short opCode)
						//	{
						//		switch (opCode)
						//		{
						//			case 1:
						//				return new ReadRequestCommandBuilder();
						//			case 2:
						//				return new WriteRequestCommandBuilder();
						//			case 3:
						//				return new DataCommandBuilder();
						//			case 5:
						//				return new TFTPErrorCommandBuilder();
						//			case 4:
						//				return new AckCommandBuilder();
						//			case 7:
						//				return new LoginRequestCommandBuilder();
						//			case 8:
						//				return new DeleteRequestCommandBuilder();
						//			case 9:
						//				return new BroadcastCommandBuilder();
						//		}
						//		//Todo make an error
						//		return nullptr;
						//	}

//JAVA TO C++ CONVERTER TODO TASK: There is no equivalent in C++ to Java static interface methods:
//							static bgu.spl171.net.impl.TFTP.Commands.Command createCommand(short opCode)
						//	{
						//		switch (opCode)
						//		{
						//			case 6:
						//				return new DirlistRequest();
						//			case 10:
						//				return new DisconnectRequest();
						//		}
						//		return nullptr;
						//	}
						};

					}
				}
			}
		}
	}
}
