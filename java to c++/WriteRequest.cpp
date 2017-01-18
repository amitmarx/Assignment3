#include "WriteRequest.h"

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

						WriteRequest::WriteRequest(const std::wstring &fileName)
						{
							this->fileName = fileName;
						}

						std::wstring WriteRequest::getFileName()
						{
							return fileName;
						}

						short WriteRequest::getOpCode()
						{
							return OpCode::WriteRequest::getValue();
						}
					}
				}
			}
		}
	}
}
