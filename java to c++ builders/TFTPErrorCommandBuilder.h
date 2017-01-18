#pragma once

#include "CommandBuilder.h"
#include <string>
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
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						class TFTPErrorCommandBuilder : public CommandBuilder
						{
						public:
							boost::optional<short> errorCode = boost::none;
							ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
							StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

							virtual ~TFTPErrorCommandBuilder()
							{
								delete shortEncoderDecoder;
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
