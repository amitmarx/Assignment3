#pragma once

#include "Command.h"
#include <string>

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


						class LoginRequest : public Command
						{
						public:
							std::wstring username;

							virtual std::wstring getUsername();

							LoginRequest(const std::wstring &username);

							virtual short getOpCode() override;

						};

					}
				}
			}
		}
	}
}
