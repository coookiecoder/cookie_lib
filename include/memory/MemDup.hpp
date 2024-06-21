#ifndef THE_COOKIE_LIB_MEMDUP_HPP
#define THE_COOKIE_LIB_MEMDUP_HPP

#include <Memory.hpp>

namespace the_cookie_lib {
	[[maybe_unused]] void *memdup(void *memory_source, memory_size byte);
}

#endif
