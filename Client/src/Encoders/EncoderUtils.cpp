#include "../../include/Encoders/EncoderUtils.h"
std::vector<char> EncoderUtils::mergeByteArray(std::vector<std::vector<char>> arrays) {
		std::vector<char> result;
		for (std::vector<char> array_Renamed :
			arrays)
		{
			result.reserve(result.size()+array_Renamed.size());
			result.insert(result.end(),array_Renamed.begin(),array_Renamed.end());
		}
		return result;
	}
