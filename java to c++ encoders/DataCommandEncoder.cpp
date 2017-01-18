#include "DataCommandEncoder.h"
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
						using bgu::spl171::net::impl::TFTP::Commands::Data;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						std::vector<char> DataCommandEncoder::encode(Command *cmd)
						{
							Data *data = static_cast<Data*>(cmd);
							std::vector<char> opCode = shortEncoderDecoder->encode(data->getOpCode());
							std::vector<char> size = shortEncoderDecoder->encode(data->getSize());
							std::vector<char> blockId = shortEncoderDecoder->encode(data->getBlockId());
							return EncoderUtils::mergeByteArray(
							{
								opCode, size, blockId, data->getData(), std::vector<char>{0}
							});
						}
					}
				}
			}
		}
	}
}
