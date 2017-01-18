#include "AckCommandEncoder.h"
#include "EncoderUtils.h"

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
					namespace CommandEncoders
					{
						using bgu::spl171::net::impl::TFTP::Commands::Command;
						using bgu::spl171::net::impl::TFTP::Commands::Responses::Ack;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						std::vector<char> AckCommandEncoder::encode(Command *cmd)
						{
							Ack *ack = static_cast<Ack*>(cmd);
							std::vector<char> opCode = shortEncoderDecoder->encode(static_cast<short>(4));
							std::vector<char> blockId = shortEncoderDecoder->encode(ack->getBlockId());
							return EncoderUtils::mergeByteArray({opCode, blockId});
						}
					}
				}
			}
		}
	}
}
