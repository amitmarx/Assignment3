#pragma once

#include "CommandEncoder.h"
#include <vector>

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
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::ShortEncoderDecoder;

						class DataCommandEncoder : public CommandEncoder
						{

						private:
							ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
						public:
							virtual ~DataCommandEncoder()
							{
								delete shortEncoderDecoder;
							}

							virtual std::vector<char> encode(Command *cmd) override;
						};

					}
				}
			}
		}
	}
}
