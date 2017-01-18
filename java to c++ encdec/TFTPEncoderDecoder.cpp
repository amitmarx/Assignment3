#include "TFTPEncoderDecoder.h"
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
						using bgu::spl171::net::api::MessageEncoderDecoder;
						using bgu::spl171::net::impl::TFTP::CommandBuilders::CommandBuilder;
						using bgu::spl171::net::impl::TFTP::CommandEncoders::CommandEncoder;
						using bgu::spl171::net::impl::TFTP::Commands::Command;

						Command *TFTPEncoderDecoder::decodeNextByte(char nextByte)
						{
							Command *returnValue = nullptr;

							if (builder == nullptr)
							{
								boost::optional<short> opCode = shortEncoderDecoder->decodeNextByte(nextByte);
								if (opCode)
								{
									builder = CommandBuilder::createBuilder(opCode);
									if (builder == nullptr)
									{
										returnValue = CommandBuilder::createCommand(opCode);
									}
								}
							}
							else
							{
								returnValue = builder->decodeNextByte(nextByte);
								if (returnValue != nullptr)
								{
									builder = nullptr;
								}
							}
							return returnValue;
						}

						std::vector<char> TFTPEncoderDecoder::encode(Command *message)
						{
							return CommandEncoder->get(message->getOpCode()).encode(message);
						}
					}
				}
			}
		}
	}
}
