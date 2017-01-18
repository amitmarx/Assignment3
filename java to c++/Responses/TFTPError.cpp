#include "TFTPError.h"

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

							std::wstring TFTPError::getErrorMsg()
							{
								return errorMsg;
							}

							short TFTPError::getErrorCode()
							{
								return errorCode;
							}

							TFTPError::TFTPError(short errorCode, const std::wstring &errorMsg)
							{
								this->errorMsg = errorMsg;
								this->errorCode = errorCode;
							}

							TFTPError::TFTPError(short errorCode)
							{
								this->errorMsg = errorMessages[errorCode];
								this->errorCode = errorCode;
							}

							TFTPError::TFTPError(int errorCode) : TFTPError((short)errorCode)
							{
							}

							short TFTPError::getOpCode()
							{
								return static_cast<short>(5);
							}

							std::wstring TFTPError::errorMessage()
							{
								return errorMsg;
							}

std::vector<std::wstring> TFTPError::errorMessages = {L"Not defined, see error message (if any).", L"File not found", L"Access violation", L"Disk full or allocation exceeded", L"Illegal TFTP operation", L"File already exists", L"User not logged in", L"User already logged in"};
						}
					}
				}
			}
		}
	}
}
