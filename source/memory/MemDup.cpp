#include <MemDup.hpp>

using namespace the_cookie_lib;

void *memdup (void *memory_source, memory_size size) {
	auto* buffer = new char[size];

	for (int cursor = 0; cursor < size; ++cursor) {
		buffer[cursor] = static_cast<char *>(memory_source)[cursor];
	}

	return buffer;
}