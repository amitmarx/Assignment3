#pragma once

#include <vector>
#include <boost/optional.hpp>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace bgu { namespace spl171 { namespace net { namespace impl { namespace TFTP { namespace EncoderDecoders { class ShortEncoderDecoder; } } } } } }

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
						using bgu::spl171::net::impl::TFTP::Commands::Command;


						class TFTPEncoderDecoder : public MessageEncoderDecoder<Command*>
						{

						public:
							ShortEncoderDecoder *shortEncoderDecoder = new ShortEncoderDecoder();
							CommandBuilder *builder = nullptr;

							virtual ~TFTPEncoderDecoder()
							{
								delete shortEncoderDecoder;
								delete builder;
							}

							virtual Command *decodeNextByte(char nextByte) override;

							virtual std::vector<char> encode(Command *message) override;

						};

					}
				}
			}
		}
	}
}
