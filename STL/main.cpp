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

// Containers are objects that store other objects.

int main()
{
	std::array<int, 10> a{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// [문제] a의 모든 데이터를 화면에 출력하라
	std::array<int, 10>::iterator p = a.begin();

	save("main.cpp");
}

// Seqeunce Container 
// array
// vector
// deque
// forward-list
// list
// - 원하는 위치에 바로 Read & Write 

// Associative Container - O(logN)
// Unordered Associative Container - O(1)

// Iterator