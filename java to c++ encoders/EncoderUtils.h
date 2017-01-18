#pragma once

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
					namespace CommandEncoders
					{

						class EncoderUtils
						{

						public:
							static std::vector<char> mergeByteArray(std::vector<char> &arrays);
						};

					}
				}
			}
		}
	}
}
