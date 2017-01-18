#pragma once

#include <vector>
#include <boost/optional.hpp>

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


						class ShortEncoderDecoder
						{
						private:
							ByteBuffer *const shortBuffer = ByteBuffer::allocate(2);

						public:
							virtual ~ShortEncoderDecoder()
							{
								delete shortBuffer;
							}

							virtual boost::optional<short> decodeNextByte(char nextByte);
						private:
							short bytesToShort(ByteBuffer *byteArr);
						public:
							virtual std::vector<char> encode(short num);
						};

					}
				}
			}
		}
	}
}
