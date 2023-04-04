//-----------------------------------------------------------------------------
// String.cpp - 자원을 확보하는 클래스
// 2023. 4. 3
//-----------------------------------------------------------------------------

#include <string>
#include <iostream>
#include "String.h"

bool 관찰{ false };				// 관찰하고 싶으면 true로 변경

String::String()
{
	print("디폴트 생성자");
}

String::String(const char* str) : len{ strlen(str) }
{
	p = new char[len];
	memcpy(p, str, len);

	print("생성자(char*)");
}

String::~String()
{
	print("소멸자");
	delete[] p;
}

// 복사생성자와 복사할당연산자
String::String(const String& other) : len{ other.len }
{
	p = new char[len];
	memcpy(p, other.p, len);

	print("복사생성");
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;

	delete[] p;

	len = other.len;
	p = new char[len];
	memcpy(p, other.p, len);

	print("복사할당연산자");
	return *this;
}

// 이동생성자와 이동할당연산자
String::String(String&& other) // && - r-value referens
{
	len = other.len;
	p = other.p;

	// other를 정리한다. -> dangling ptr 방지
	other.len = 0;
	other.p = nullptr;

	print("이동생성자");
}

String& String::operator=(String&& other)
{
	if (this == &other)
		return *this;

	// 내가 확보한 자원 해제
	delete[] p;

	// other 자원을 가져온다
	len = other.len;
	p = other.p;

	// other를 초기화한다
	other.len = 0;
	other.p = nullptr;

	print("이동할당연산자");

	return *this;
}

// 연산자 오버로딩 함수들
String String::operator+(const String& rhs) const
{
	String temp;
	temp.len = len + rhs.len;
	temp.p = new char[temp.len];
	memcpy(temp.p, p, len);
	memcpy(temp.p + len, rhs.p, rhs.len);
	return temp;
}

// gettor / settor
std::string String::getString() const
{
	return std::string(p, len);
}

// 2023. 4. 4 추가
size_t String::getSize() const
{
	return len;
}

// 그 외 함수들
void String::print(const char* msg) const
{
	if (관찰) {
		std::cout << "[" << id << "] - " << msg << ", 개수: " << len
			<< ", 주소: " << (void*)p << std::endl;
	}
}

size_t String::sid{ 0 };