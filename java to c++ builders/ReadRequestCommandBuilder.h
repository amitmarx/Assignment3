#pragma once

#include "CommandBuilder.h"
#include <string>

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
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;


						class ReadRequestCommandBuilder : public CommandBuilder
						{

						public:
							StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

							virtual ~ReadRequestCommandBuilder()
							{
								delete stringEncoderDecoder;
							}

							virtual Command *decodeNextByte(char nextByte) override;
						};

					}
				}
			}
		}
	}
}
