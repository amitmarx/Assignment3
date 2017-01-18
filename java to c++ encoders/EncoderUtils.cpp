#include "EncoderUtils.h"

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

						std::vector<char> EncoderUtils::mergeByteArray(std::vector<char> &arrays)
						{
							int size = 0;
							for (char[] array_Renamed : arrays)
							{
								size += array_Renamed.size();
							}
							std::vector<char> result(size);

							int index = 0;
							for (char[] array_Renamed : arrays)
							{
								System::arraycopy(array_Renamed, 0, result, index, array_Renamed.size());
								index += array_Renamed.size();
							}
							return result;
						}
					}
				}
			}
		}
	}
}
