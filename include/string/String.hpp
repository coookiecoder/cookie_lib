#ifndef THE_COOKIE_LIB_STRING_HPP
#define THE_COOKIE_LIB_STRING_HPP

namespace the_cookie_lib {
	typedef unsigned long long int string_len;

	class String {
		private:
			char *data{};
			string_len len{};
		public:
			String();
			~String();
			String(char *string);
			String(String& string);
		public:
			String* operator+(String& left_part);
			String* operator&(String& left_part);
			String& operator=(String left_part);
			String& operator=(const String& left_part);
			String& operator=(String&& left_part) noexcept;
			bool operator<(String& left_part) const;
			bool operator>(String& left_part) const;
			String* operator+=(String& left_part);
			String* operator&=(String& left_part);
			bool operator==(String& left_part);
			bool operator!=(String& left_part);
			char operator[](int left_part);
			char operator[](string_len left_part);
	};

	string_len strlen(String& string);
	string_len strlen(const char* string);
}


#endif //THE_COOKIE_LIB_STRING_HPP
