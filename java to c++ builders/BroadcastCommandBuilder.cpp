#include "BroadcastCommandBuilder.h"

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
						using bgu::spl171::net::impl::TFTP::Commands::ReadRequest;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						Command *BroadcastCommandBuilder::decodeNextByte(char nextByte)
						{
							if (isAdded)
							{
								std::wstring fileName = stringEncoderDecoder->decodeNextByte(nextByte);
								if (fileName != L"")
								{
									return new ReadRequest(fileName);
								}
							}
							else
							{
								isAdded = nextByte == 1;
							}
							return nullptr;
						}
					}
				}
			}
		}
	}
}
