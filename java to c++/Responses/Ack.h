#pragma once

#include "Response.h"

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
						namespace Responses
						{

							class Ack : public Response
							{
							public:
								short blockId = 0;

								Ack(short blockId);
								Ack();

								virtual short getBlockId();

								virtual short getOpCode() override;

							};

						}
					}
				}
			}
		}
	}
}
