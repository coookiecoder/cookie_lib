#ifndef THE_COOKIE_LIB_STRING_HPP
#define THE_COOKIE_LIB_STRING_HPP

namespace the_cookie_lib {
	typedef unsigned long long int string_len;

	class String {
		private:
			char *data{};
			string_len len{};
		public:
			[[maybe_unused]] String();
			[[maybe_unused]] ~String();
			[[maybe_unused]] String(char *string);
			[[maybe_unused]] String(String& string);
		public:
			[[maybe_unused]] String* operator+(String& left_part);
			[[maybe_unused]] String* operator&(String& left_part);
			[[maybe_unused]] String& operator=(String left_part);
			[[maybe_unused]] String& operator=(const String& left_part);
			[[maybe_unused]] String& operator=(String&& left_part) noexcept;
			[[maybe_unused]] bool operator<(String& left_part) const;
			[[maybe_unused]] bool operator>(String& left_part) const;
			[[maybe_unused]] String* operator+=(String& left_part);
			[[maybe_unused]] String* operator&=(String& left_part);
			[[maybe_unused]] bool operator==(String& left_part);
			[[maybe_unused]] bool operator!=(String& left_part);
			[[maybe_unused]] char operator[](int left_part);
			[[maybe_unused]] char operator[](string_len left_part);
	};
}

#include <StrLen.hpp>

#endif //THE_COOKIE_LIB_STRING_HPP
