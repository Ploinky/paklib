#pragma once

#include <string>

namespace paklib {
	class PakFileTableEntry {
	public:
		uint64_t FilePathLength;
		std::string FilePath;
		uint64_t Offset = 0;
		uint64_t Size = 0;
	};
}