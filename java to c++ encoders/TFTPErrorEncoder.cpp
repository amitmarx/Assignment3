#include "TFTPErrorEncoder.h"
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
						using bgu::spl171::net::impl::TFTP::Commands::Responses::TFTPError;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						std::vector<char> TFTPErrorEncoder::encode(Command *cmd)
						{
							TFTPError *error = static_cast<TFTPError*>(cmd);
							std::vector<char> opCode = shortEncoderDecoder->encode(error->getOpCode());
							std::vector<char> errorCode = shortEncoderDecoder->encode(error->getErrorCode());
							std::vector<char> errorMsg = stringEncoderDecoder->encode(error->errorMessage());
							return EncoderUtils::mergeByteArray({opCode, errorCode, errorMsg});
						}
					}
				}
			}
		}
	}
}
