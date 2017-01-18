#include "LoginRequest.h"

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

						std::wstring LoginRequest::getUsername()
						{
							return username;
						}

						LoginRequest::LoginRequest(const std::wstring &username)
						{
							this->username = username;
						}

						short LoginRequest::getOpCode()
						{
							return OpCode::Login::getValue();
						}
					}
				}
			}
		}
	}
}
