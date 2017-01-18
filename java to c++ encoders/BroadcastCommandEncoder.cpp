#include "BroadcastCommandEncoder.h"
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
						using bgu::spl171::net::impl::TFTP::Commands::Broadcast;
						using bgu::spl171::net::impl::TFTP::Commands::Command;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						std::vector<char> BroadcastCommandEncoder::encode(Command *cmd)
						{
							Broadcast *broadcast = static_cast<Broadcast*>(cmd);
							std::vector<char> opCode = shortEncoderDecoder->encode(static_cast<short>(9));
							std::vector<char> isAdded = broadcast->isAdded() ? std::vector<char>{static_cast<char>(1)} : std::vector<char>{static_cast<char>(0)};
							std::vector<char> fileName = broadcast->getFileName().getBytes();

							return EncoderUtils::mergeByteArray(
							{
								opCode, isAdded, fileName, std::vector<char>{0}
							});

						}
					}
				}
			}
		}
	}
}
