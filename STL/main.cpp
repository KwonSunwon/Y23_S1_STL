//-------------------------------------------------------
// 2023 1학기 STL 4월 4일 (5주 2)
//-------------------------------------------------------
// Sequence Container - array
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"

int main()
{
	std::array<int, 10> a{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// [문제] a의 모든 데이터를 화면에 출력하라
	for (auto p = a.begin(); p != a.end(); ++p) // 어떤 STL 자료구조든 문제 없이 사용 가능 -> 표준
		std::cout << *p << ' ';
	std::cout << std::endl;

	for (int i = 0; i < a.size(); ++i) // array 자료구조에 종속저
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	save("main.cpp");
}
