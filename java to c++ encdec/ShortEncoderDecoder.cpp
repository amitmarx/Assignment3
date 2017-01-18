#include "ShortEncoderDecoder.h"

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

						boost::optional<short> ShortEncoderDecoder::decodeNextByte(char nextByte)
						{
							shortBuffer->put(nextByte);
							if (!shortBuffer->hasRemaining())
							{
								shortBuffer->flip();
								boost::optional<short> returnValue = bytesToShort(shortBuffer);
								shortBuffer->clear();
								return returnValue;
							}
							return boost::none;
						}

						short ShortEncoderDecoder::bytesToShort(ByteBuffer *byteArr)
						{
							short result = static_cast<short>((byteArr->get(0) & 0xff) << 8);
							result += static_cast<short>(byteArr->get(1) & 0xff);
							return result;
						}

						std::vector<char> ShortEncoderDecoder::encode(short num)
						{
							std::vector<char> bytesArr(2);
							bytesArr[0] = static_cast<char>((num >> 8) & 0xFF);
							bytesArr[1] = static_cast<char>(num & 0xFF);
							return bytesArr;
						}
					}
				}
			}
		}
	}
}
