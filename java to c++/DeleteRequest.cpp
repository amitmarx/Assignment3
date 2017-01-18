#include "DeleteRequest.h"

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

						std::wstring DeleteRequest::getFileName()
						{
							return fileName;
						}

						DeleteRequest::DeleteRequest(const std::wstring &fileName)
						{
							this->fileName = fileName;
						}

						short DeleteRequest::getOpCode()
						{
							return OpCode::Delete::getValue();
						}
					}
				}
			}
		}
	}
}
