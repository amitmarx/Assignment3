#include "AckCommandBuilder.h"

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
						using bgu::spl171::net::impl::TFTP::Commands::Responses::Ack;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						Command *AckCommandBuilder::decodeNextByte(char nextByte)
						{
							boost::optional<short> blockId = shortEncoderDecoder->decodeNextByte(nextByte);
							if (blockId != nullptr)
							{
								return new Ack(blockId);
							}
							return nullptr;
						}
					}
				}
			}
		}
	}
}
