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


						class DeleteRequest : public Command
						{
						public:
							std::wstring fileName;

							virtual std::wstring getFileName();

							DeleteRequest(const std::wstring &fileName);

							virtual short getOpCode() override;

						};

					}
				}
			}
		}
	}
}
