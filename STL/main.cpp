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
#include "save.h"
#include "String.h"

int main()
{
	extern bool 관찰;
	관찰 = true;

	std::array<String, 3> a{ "345", "12", "67890" };

	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
			  });

	for (const String& s : a)
		std::cout << s << std::endl;

	save("main.cpp");
}
