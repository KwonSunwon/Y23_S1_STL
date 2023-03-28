//-------------------------------------------------------
// 2023 1학기 STL 3월 28일 (4주 2)
//-------------------------------------------------------
// C++ 클래스 복습 - String 클래스를 만든다.
// 앞으로 String 클래스를 STL 컨테이너로 발전시킨다.
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"

class String {
	size_t len{};
	char* p{};		// [도전] unique_ptr<char> p 로 바꿔서 코딩해 볼 것

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

	String(const char* str) : len{ strlen(str) }
	{
		p = new char[len];
		memcpy(p, str, len);	// DMA: Direct Memory Access - CPU 접근없이 바로 메모리에 접근
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

};

int main()
{
	String a{ "123" }; // 개수가 많아져도 32바이트 크기를 유지 -> 동적 할당을 한다.

	std::cout << a << '\n';

	save("main.cpp");
}
