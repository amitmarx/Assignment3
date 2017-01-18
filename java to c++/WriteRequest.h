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


						class WriteRequest : public Command
						{

						public:
							std::wstring fileName;
							WriteRequest(const std::wstring &fileName);

							virtual std::wstring getFileName();

							virtual short getOpCode() override;

						};

					}
				}
			}
		}
	}
}
