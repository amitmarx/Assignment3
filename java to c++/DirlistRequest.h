#pragma once

#include "Command.h"

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


						class DirlistRequest : public Command
						{
						public:
							virtual short getOpCode() override;
						};

					}
				}
			}
		}
	}
}
