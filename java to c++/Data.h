#pragma once

#include "Responses/Response.h"
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
					namespace Commands
					{

						using Response = bgu::spl171::net::impl::TFTP::Commands::Responses::Response;

						class Data : public Response
						{
						public:
							short size = 0;
							short blockId = 0;
							std::vector<char> data;

							Data(short size, short blockId, std::vector<char> &data);

							virtual short getSize();

							virtual short getBlockId();

							virtual std::vector<char> getData();

							virtual bool isFinalMessage();

							virtual short getOpCode() override;
						};

					}
				}
			}
		}
	}
}
