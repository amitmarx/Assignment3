#include "WriteRequestCommandBuilder.h"

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
						using bgu::spl171::net::impl::TFTP::Commands::WriteRequest;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						Command *WriteRequestCommandBuilder::decodeNextByte(char nextByte)
						{
							std::wstring fileName = stringEncoderDecoder->decodeNextByte(nextByte);
							if (fileName != L"")
							{
								return new WriteRequest(fileName);
							}
							return nullptr;
						}
					}
				}
			}
		}
	}
}
