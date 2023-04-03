//-------------------------------------------------------
// 2023 1학기 STL 4월 3일 (5주 1)
//-------------------------------------------------------
// String 클래스 파일 분리
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include "save.h"

// [문제] String을 코딩하라
// 모든 special 함수의 관찰 메시지를 추가하라
// 생성시 객체에 고유번호를 부여하라

bool 관찰{ false };

class String
{
	size_t len{};				// 확보한 자원의 바이트 수
	char* p{};					// 확보한 자원의 주소
	size_t id = ++sid;			// 객체의 고유번호

	static size_t sid;			// 클래스 스태틱

public:
	String()
	{
		print("디폴트 생성자");
	}
	String(const char* str) : len{ strlen(str) }
	{
		p = new char[len];
		memcpy(p, str, len);

		print("생성자(char*)");
	}
	~String()
	{
		print("소멸자");
		delete[] p;
	}

	// 복사생성자와 복사할당연산자
	String(const String& other) : len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);

		print("복사생성");
	}
	String& operator=(const String& other)
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
	String(String&& other) // && - r-value referens
	{
		len = other.len;
		p = other.p;

		// other를 정리한다. -> dangling ptr 방지
		other.len = 0;
		other.p = nullptr;

		print("이동생성자");
	}

	String& operator=(String&& other)
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

	String operator+(const String& rhs) const
	{
		String temp;
		temp.len = len + rhs.len;
		temp.p = new char[temp.len];
		memcpy(temp.p, p, len);
		memcpy(temp.p + len, rhs.p, rhs.len);
		return temp;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

	// gettor / settor
	std::string getString() const
	{
		return std::string(p, len);
	}

	// 그 외 함수들
	void print(const char* msg) const
	{
		if (관찰)
		{
			std::cout << "[" << id << "] - " << msg << ", 개수: " << len
				<< ", 주소: " << (void*)p << '\n';
		}
	}
};

size_t String::sid{ 0 };

int main()
{
	관찰 = true;
	String a{ "12345" };
	String b{ "4567890" };
	b = std::move(a);

	std::cout << a << '\n';
	std::cout << b << '\n';

	save("main.cpp");
}
