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
						using bgu::spl171::net::impl::TFTP::EncoderDecoders::StringEncoderDecoder;

						class TFTPErrorEncoder : public CommandEncoder
						{
						private:
							ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
							StringEncoderDecoder *stringEncoderDecoder = new StringEncoderDecoder();

						public:
							virtual ~TFTPErrorEncoder()
							{
								delete shortEncoderDecoder;
								delete stringEncoderDecoder;
							}

							virtual std::vector<char> encode(Command *cmd) override;
						};

					}
				}
			}
		}
	}
}
