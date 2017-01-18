#include "Ack.h"

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

							Ack::Ack(short blockId)
							{
								this->blockId = blockId;
							}

							Ack::Ack()
							{
								this->blockId = static_cast<short>(0);
							}

							short Ack::getBlockId()
							{
								return blockId;
							}

							short Ack::getOpCode()
							{
								return OpCode::Ack::getValue();
							}
						}
					}
				}
			}
		}
	}
}
