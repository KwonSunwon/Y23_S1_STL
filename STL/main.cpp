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

class String {
	size_t len{};
	char* p{};		// [도전] unique_ptr<char> p 로 바꿔서 코딩해 볼 것

	size_t id = ++sid; // 객체의 고유번호

	static size_t sid;

public:
	/*String(const char str[])
	{
		len = strlen(str);
		p = new char[len + 1];
		strcpy(p, str);
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		return os << s.p; // 정상 작동 한다고 해도 잘못된 코드, string 은 마지막 널을 유지하지 않는다
	}*/
	String()
	{
		print("디폴트 생성");
	}
	String(const char* str) : len{ strlen(str) }
	{
		p = new char[len];
		memcpy(p, str, len);	// DMA: Direct Memory Access - CPU 접근없이 바로 메모리에 접근

		print("생성(char*)");
	}
	~String()
	{
		print("소멸자");
		delete[] p;
	}

	// 복사 생성
	/*String(const String& s) : len{ s.len }
	{
		p = new char[len];
		memcpy(p, s.p, len);

		print("복사생성");
	}*/
	String(const String& other) : len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);

		print("복사생성");
	}
	// 복사생성자를 코딩했다면 복사할당연산자도 반드시 코딩해야함
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

	/*String operator+(const String& other) // 함수에 const 붙여줘야 한다.
	{
		String temp;
		temp.len = this->len + other.len;
		temp.p = new char[temp.len];
		memcpy(temp.p, this->p, this->len);
		memcpy(temp.p + this->len, other.p, other.len);
		return temp;
	}*/
	String operator+(const String& rhs) const
	{
		String temp; // 오류가 생긴다면 default 생성자가 없기 때문 String() = default 추가
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

	std::string getString() const
	{
		return std::string(p, len);
	}

	void print(const char* msg) const
	{
		if (관찰) {
			std::cout << "[" << id << "] - " << msg << ", 개수: " << len
				<< ", 주소: " << (void*)p << '\n';
		}
	}
};

size_t String::sid{ 0 };

int main()
{
	관찰 = true;
	// [과제] 객체가 3개일 때 메모리에 어떤 일이 일어나는지 확인해보기
	std::array<String, 3> news{ "안정성", "여부", "검증"};

	// [문제] news를 오름차순 정렬하라
	std::sort(news.begin(), news.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});


	for (String& s : news)
		std::cout << s << '\n';

	//save("main.cpp");
}
