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
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						class BroadcastCommandBuilder : public CommandBuilder
						{
						public:
							boost::optional<bool> isAdded = boost::none;
							StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

							virtual ~BroadcastCommandBuilder()
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
