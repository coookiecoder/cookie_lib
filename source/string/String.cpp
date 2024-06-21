#include <String.hpp>
#include <stdexcept>

using namespace the_cookie_lib;

String::String() {
	this->data = nullptr;
	this->len = 0;
}

String::~String() {
	delete[] this->data;
}

String::String(char *string) {
	this->len = strlen(string);
	this->data = new char[this->len + 1];

	for (int cursor = 0; string[cursor]; ++cursor) {
		this->data[cursor] = string[cursor];
	}

	this->data[this->len] = '\0';
}

String::String(the_cookie_lib::String &string) {
	this->len = string.len;
	this->data = new char[this->len + 1];

	for (int cursor = 0; string.len && string[cursor]; ++cursor) {
		this->data[cursor] = string[cursor];
	}

	this->data[this->len] = '\0';
}

String *String::operator+(String &left_part) {
	auto* result = new String;
	int offset = 0;

	result->len = this->len + left_part.len;
	result->data = new char[result->len + 1];

	for (int cursor = 0; this->len && (*this)[cursor]; cursor++) {
		result->data[offset++] = (*this)[cursor];
	}

	for (int cursor = 0; left_part.len && left_part[cursor]; cursor++) {
		result->data[offset++] = left_part[cursor];
	}

	result->data[result->len] = '\0';

	return result;
}

String *String::operator&(String &left_part) {
	auto* result = new String;
	int cursor = 0;

	if (this->len > left_part.len)
		result->len = this->len;
	else
		result->len = left_part.len;

	result->data = new char[result->len + 1];

	while (this->data[cursor] && left_part.data[cursor]) {
		if (this->data[cursor] == left_part.data[cursor])
			result->data[cursor] = this->data[cursor];
		else
			result->data[cursor] = 1;
		cursor++;
	}

	while (cursor < result->len) {
		result->data[cursor++] = 1;
	}

	result->data[result->len] = '\0';
	return result;
}

String &String::operator=(String left_part) {
	this->len = left_part.len;
	this->data = new char[this->len + 1];

	for (int cursor = 0; left_part.len && left_part[cursor]; ++cursor) {
		this->data[cursor] = left_part[cursor];
	}

	this->data[this->len] = '\0';
	return *this;
}

String &String::operator=(const String &left_part) {
	if (this!= &left_part) {
		delete[] this->data;

		this->len = left_part.len;
		this->data = new char[this->len + 1];

		for (int cursor = 0; left_part.len && left_part.data[cursor]; ++cursor) {
			this->data[cursor] = left_part.data[cursor];
		}

		this->data[this->len] = '\0';
	}
	return *this;
}

String &String::operator=(String &&left_part) noexcept {
	if (this != &left_part) {
		delete[] this->data;

		this->data = left_part.data;
		this->len = left_part.len;

		left_part.data = nullptr;
		left_part.len = 0;
	}

	return *this;
}

bool String::operator<(String &left_part) const {
	return this->len < left_part.len;
}

bool String::operator>(String &left_part) const {
	return this->len > left_part.len;
}

String *String::operator+=(String& left_part) {
	auto* result = new String;
	int offset = 0;

	result->len = this->len + left_part.len;
	result->data = new char[result->len + 1];

	for (int cursor = 0; this->len && (*this)[cursor]; cursor++) {
		result->data[offset++] = (*this)[cursor];
	}

	for (int cursor = 0; left_part.len && left_part[cursor]; cursor++) {
		result->data[offset++] = left_part[cursor];
	}

	result->data[result->len] = '\0';

	return result;
}

String *String::operator&=(String& left_part) {
	auto* result = new String;
	int cursor = 0;

	if (this->len > left_part.len)
		result->len = this->len;
	else
		result->len = left_part.len;

	result->data = new char[result->len + 1];

	while (this->data[cursor] && left_part.data[cursor]) {
		if (this->data[cursor] == left_part.data[cursor])
			result->data[cursor] = this->data[cursor];
		else
			result->data[cursor] = 1;
		cursor++;
	}

	while (cursor < result->len) {
		result->data[cursor++] = 1;
	}

	result->data[result->len] = '\0';

	return result;
}

bool  String::operator==(String& left_part) {
	int cursor = 0;

	while (this->len && left_part.len && (*this)[cursor] && left_part[cursor]) {
		if ((*this)[cursor] != left_part[cursor]) {
			return false;
		} else {
			cursor++;
		}
	}
	return (*this)[cursor] == left_part[cursor];
}

bool String::operator!=(String& left_part) {
	int cursor = 0;

	while (this->len && left_part.len && (*this)[cursor] && left_part[cursor]) {
		if ((*this)[cursor] == left_part[cursor]) {
			return false;
		} else {
			cursor++;
		}
	}
	return (*this)[cursor] == left_part[cursor];
}

char String::operator[](int left_part) {
	if (left_part > this->len)
		throw (std::invalid_argument("invalid index"));
	else if (this->data == nullptr)
		throw (std::invalid_argument("string empty"));
	else
		return this->data[left_part];
}

char String::operator[](string_len left_part) {
	if (left_part > this->len)
		throw (std::invalid_argument("invalid index"));
	else if (this->data == nullptr)
		throw (std::invalid_argument("string empty"));
	else
		return this->data[left_part];
}