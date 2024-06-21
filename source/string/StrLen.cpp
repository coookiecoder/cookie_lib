#include "string/String.hpp"

the_cookie_lib::string_len the_cookie_lib::strlen(const char *string) {
	the_cookie_lib::string_len result = 0;

	while (string[result]) {
		result++;
	}

	return result;
}

the_cookie_lib::string_len the_cookie_lib::strlen(String &string) {
	the_cookie_lib::string_len result = 0;

	while (string[result]) {
		result++;
	}

	return result;
}