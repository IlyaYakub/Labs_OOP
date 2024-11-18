#pragma once

#include <iostream>

class String
{
public:
	String(const char* text = nullptr) noexcept;
	String(const String& Str)    noexcept;

	void Input() const;
	bool  operator!() const;
	char* operator()(int begin, int end) const;
	char  operator[](int index) const;

	friend std::ostream& operator<<(std::ostream& out, const String& Str);

	~String() noexcept;

private:
	char* str;
};