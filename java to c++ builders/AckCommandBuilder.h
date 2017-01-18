#pragma once

#include "CommandBuilder.h"
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
					namespace CommandBuilders
					{

						using bgu::spl171::net::impl::TFTP::Commands::Command;
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						class AckCommandBuilder : public CommandBuilder
						{
						public:
							ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();

							virtual ~AckCommandBuilder()
							{
								delete shortEncoderDecoder;
							}

							virtual Command *decodeNextByte(char nextByte) override;
						};

					}
				}
			}
		}
	}
}
