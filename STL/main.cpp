//-------------------------------------------------------
// 2023 1학기 STL 4월 4일 (5주 2)
//-------------------------------------------------------
// Sequence Container - array
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

int main()
{
	//std::array<std::string, 100> a; // 동일하게 동작해야 한다.
	std::array<String, 100> a;

	// [문제] a에 "main.cpp" 단어 100개를 읽어와라.
	std::ifstream in{ "main.cpp" };

	for (int i = 0; i < 100; ++i) {
		in >> a[i];
	}

	// 길이 오름차순으로 정렬한 후 출력한다.
	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});

	for (int i = 0; i < 100; ++i) {
		std::cout << a[i] << std::endl;
	}

	save("main.cpp");
}
