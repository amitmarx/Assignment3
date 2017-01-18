#include "LoginRequestCommandBuilder.h"

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
						using bgu::spl171::net::impl::TFTP::Commands::LoginRequest;
						using bgu::spl171::net::impl::TFTP::Commands::ReadRequest;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						Command *LoginRequestCommandBuilder::decodeNextByte(char nextByte)
						{
							std::wstring username = stringEncoderDecoder->decodeNextByte(nextByte);
							if (username != L"")
							{
								return new LoginRequest(username);
							}
							return nullptr;
						}
					}
				}
			}
		}
	}
}
