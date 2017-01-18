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

						class AckCommandEncoder : public CommandEncoder
						{
						public:
							ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
							virtual ~AckCommandEncoder()
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
