//-------------------------------------------------------
// 2023 1학기 STL 4월 10일 (6주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << sizeof(v) << std::endl;
	std::cout << v.size() << std::endl;		// 1 멤버
	std::cout << v.data() << std::endl;		// 2 멤버
	std::cout << v.capacity() << std::endl; // 3 멤버

	v.push_back(11);
	std::cout << v.size() << std::endl;
	std::cout << v.data() << std::endl;
	std::cout << v.capacity() << std::endl;

	save("main.cpp");
}
