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
					namespace Commands
					{


						class Command
						{
						public:
							virtual short getOpCode() = 0;

//JAVA TO C++ CONVERTER TODO TASK: Interface inner types are not converted:
//							enum OpCode
						//	{
						//		ReadRequest,
						//		WriteRequest,
						//		Data,
						//		Ack,
						//		Error,
						//		Dirlist,
						//		Login,
						//		Delete,
						//		Broadcast,
						//		Disconnect;
						//
						//		public short getValue()
						//		{
						//			return (short)(ordinal() + 1);
						//		}
						//	}
						};

					}
				}
			}
		}
	}
}
