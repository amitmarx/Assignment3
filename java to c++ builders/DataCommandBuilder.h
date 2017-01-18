#pragma once

#include "CommandBuilder.h"
#include <vector>
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

						class DataCommandBuilder : public CommandBuilder
						{
						public:
							boost::optional<short> size = boost::none;
							boost::optional<short> blockId = boost::none;
						private:
							std::vector<char> data;
							int index = 0;
							ShortEncoderDecoder *const shortEncoderDecoder = new ShortEncoderDecoder();

						public:
							virtual ~DataCommandBuilder()
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
