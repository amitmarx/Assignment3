#include "DataCommandBuilder.h"

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
						using bgu::spl171::net::impl::TFTP::Commands::Data;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						Command *DataCommandBuilder::decodeNextByte(char nextByte)
						{
							if (!size)
							{
								size = shortEncoderDecoder->decodeNextByte(nextByte);
								data = std::vector<char>(size);
							}
							else if (!blockId)
							{
								blockId = shortEncoderDecoder->decodeNextByte(nextByte);
							}
							else
							{
								data[index] = nextByte;
								if (++index == size)
								{
									return new Data(size, blockId, data);
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
