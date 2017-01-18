#pragma once

#include <string>
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
					namespace EncoderDecoders
					{



						class StringEncoderDecoder
						{
						public:
							std::vector<char> stringBuffer;

							virtual std::wstring decodeNextByte(char nextByte);

						private:
							std::wstring getString();
						public:
							virtual std::vector<char> encode(const std::wstring &str);
						};

					}
				}
			}
		}
	}
}
