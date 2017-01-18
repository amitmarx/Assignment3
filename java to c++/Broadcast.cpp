#include "Broadcast.h"

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

						Broadcast::Broadcast(bool isAdded, const std::wstring &fileName)
						{
							this->isAdded_Renamed = isAdded;
							this->fileName = fileName;
						}

						bool Broadcast::isAdded()
						{
							return isAdded_Renamed;
						}

						std::wstring Broadcast::getFileName()
						{
							return fileName;
						}

						short Broadcast::getOpCode()
						{
							return OpCode::Broadcast::getValue();
						}
					}
				}
			}
		}
	}
}
