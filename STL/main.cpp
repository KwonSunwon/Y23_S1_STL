//-------------------------------------------------------
// 2023 1학기 STL 4월 11일 (6주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
// 1. 공간을 예약하고 사용하자(재할당이 발생하지 않도록 주의)
// 2. push_back 대신에 emplace_back 을 사용하자
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	extern bool 관찰;
	관찰 = true;

 	vector<String> v;
	v.reserve(3);
	v.emplace_back("123");

	관찰 = false;

	save("main.cpp");
}
