#include <string>
#include <iostream>
#include <format>
#include "String.h"

bool observe{ false };

String::String() 
{
	print("default constructor");
}

String::String(const char* s) : len{ strlen(s) } 
{
	p = std::make_unique<char>(len);
	memcpy(p.get(), s, len);

	print("constructor(char*)");
}

String::~String() 
{
	print("destructor");
}

String::String(const String& other) : len{ other.len }
{
	p = std::make_unique<char>(len);
	memcpy(p.get(), other.p.get(), len);

	print("copy constructor");
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;

	p.reset();

	len = other.len;
	p = std::make_unique<char>(len);
	memcpy(p.get(), other.p.get(), len);

	print("copy assignment");
	return *this;
}

String::String(String&& other)
{
	len = other.len;
	p = move(other.p);

	other.len = 0;

	print("move constructor");
}

String& String::operator=(String&& other)
{
	if(this == &other)
		return *this;

	len = other.len;
	p = move(other.p);

	other.len = 0;
	
	print("move assignment");
	return *this;
}

String String::operator+(const String& rhs) const 
{
	String temp;
	temp.len = len + rhs.len;
	temp.p = std::make_unique<char>(temp.len);
	memcpy(temp.p.get(), p.get(), len);
	memcpy(temp.p.get() + len, rhs.p.get(), rhs.len);
	return temp;
}

std::string String::getString() const 
{
	return std::string(p.get(), len);
}

void String::print(const char* msg) const 
{
	if (observe) {
		std::cout << std::format("[{}] - {:<20} length: {:<2d} address: ", id, msg, len);
		std::cout << static_cast<const void*>(p.get()) << '\n'; // it c++ style cast - c-style cast is (void*)p.get()
	}
}

size_t String::sid{ 0 };