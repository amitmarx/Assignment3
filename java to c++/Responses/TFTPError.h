#pragma once

#include "Response.h"
#include <string>
#include <vector>

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
						namespace Responses
						{

							class TFTPError : public Response
							{
							public:
								std::wstring errorMsg;
								short errorCode = 0;

								virtual std::wstring getErrorMsg();

								virtual short getErrorCode();

								TFTPError(short errorCode, const std::wstring &errorMsg);

								TFTPError(short errorCode);
								TFTPError(int errorCode);

								virtual short getOpCode() override;

								virtual std::wstring errorMessage();

							private:
								static std::vector<std::wstring> errorMessages;
							};

						}
					}
				}
			}
		}
	}
}
