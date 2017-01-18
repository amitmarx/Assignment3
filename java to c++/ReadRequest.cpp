#include "ReadRequest.h"

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

						ReadRequest::ReadRequest(const std::wstring &fileName)
						{
							this->fileName = fileName;
						}

						std::wstring ReadRequest::getFileName()
						{
							return fileName;
						}

						short ReadRequest::getOpCode()
						{
							return OpCode::ReadRequest::getValue();
						}
					}
				}
			}
		}
	}
}
