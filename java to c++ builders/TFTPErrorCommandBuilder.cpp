#include "TFTPErrorCommandBuilder.h"

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
						using bgu::spl171::net::impl::TFTP::Commands::Responses::TFTPError;
						using bgu::spl171::net::impl::TFTP::Commands::WriteRequest;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						Command *TFTPErrorCommandBuilder::decodeNextByte(char nextByte)
						{
							if (!errorCode)
							{
								errorCode = shortEncoderDecoder->decodeNextByte(nextByte);
							}
							else
							{
								std::wstring errorMsg = stringEncoderDecoder->decodeNextByte(nextByte);
								if (errorMsg != L"")
								{
									return new TFTPError(errorCode, errorMsg);
								}
							}
							return nullptr;
						}
					}
				}
			}
		}
	}
}
