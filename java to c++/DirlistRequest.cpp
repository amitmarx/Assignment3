#include "DirlistRequest.h"

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

						short DirlistRequest::getOpCode()
						{
							return OpCode::Dirlist::getValue();
						}
					}
				}
			}
		}
	}
}
