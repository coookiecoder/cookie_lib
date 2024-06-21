#ifndef THE_COOKIE_LIB_STRLEN_HPP
#define THE_COOKIE_LIB_STRLEN_HPP

#include <String.hpp>

namespace the_cookie_lib {
	[[maybe_unused]] string_len strlen(String &string);
	[[maybe_unused]] string_len strlen(const char *string);
}

#endif
