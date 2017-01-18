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


						class Broadcast : public Command
						{
						public:
//JAVA TO C++ CONVERTER NOTE: Fields cannot have the same name as methods:
							bool isAdded_Renamed = false;
							std::wstring fileName;

							Broadcast(bool isAdded, const std::wstring &fileName);

							virtual bool isAdded();

							virtual std::wstring getFileName();

							virtual short getOpCode() override;

						};

					}
				}
			}
		}
	}
}
