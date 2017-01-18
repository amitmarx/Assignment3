#include "DisconnectRequest.h"

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

						short DisconnectRequest::getOpCode()
						{
							return OpCode::Disconnect::getValue();
						}
					}
				}
			}
		}
	}
}
