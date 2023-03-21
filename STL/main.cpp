//-------------------------------------------------------
// 2023 1학기 STL 3월 21일 (3주 2)
//-------------------------------------------------------
// 파일 예제
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.hpp"

// [문제] "main.cpp"를 읽어 소문자를 대문자로 변환하여
// "main_upper.cpp"에 저장하라.

int main()
{
	save("main.cpp");

	std::ifstream in{ "main.cpp" };
	std::ofstream out{ "main_upper.cpp " };

	std::transform(std::istreambuf_iterator<char>{in}, {},
		std::ostreambuf_iterator<char>{out},
		[](char c) {
			return toupper(c);
		});
}
