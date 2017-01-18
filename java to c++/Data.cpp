#include "Data.h"

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

						Data::Data(short size, short blockId, std::vector<char> &data)
						{
							this->size = size;
							this->blockId = blockId;
							this->data = data;
						}

						short Data::getSize()
						{
							return size;
						}

						short Data::getBlockId()
						{
							return blockId;
						}

						std::vector<char> Data::getData()
						{
							return data;
						}

						bool Data::isFinalMessage()
						{
							return size < 512;
						}

						short Data::getOpCode()
						{
							return OpCode::Data::getValue();
						}
					}
				}
			}
		}
	}
}
