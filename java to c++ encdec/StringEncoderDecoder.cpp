#include "StringEncoderDecoder.h"

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
					namespace EncoderDecoders
					{
						using bgu::spl171::net::impl::TFTP::CommandEncoders::EncoderUtils;
						using bgu::spl171::net::impl::TFTP::Commands::Command;
						using bgu::spl171::net::impl::TFTP::Commands::ReadRequest;

						std::wstring StringEncoderDecoder::decodeNextByte(char nextByte)
						{
							if (nextByte == 0)
							{
								std::wstring returnValue = getString();
								stringBuffer.clear();
								return returnValue;
							}
							return L"";
						}

						std::wstring StringEncoderDecoder::getString()
						{
							std::vector<char> bytes(stringBuffer.size());
							for (int i = 0; i < bytes.size(); i++)
							{
								bytes[i] = stringBuffer[i];
							}
							return std::wstring(bytes);
						}

						std::vector<char> StringEncoderDecoder::encode(const std::wstring &str)
						{
							return EncoderUtils::mergeByteArray(str.getBytes(),std::vector<char>{0});
						}
					}
				}
			}
		}
	}
}
