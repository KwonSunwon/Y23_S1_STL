//-------------------------------------------------------
// 2023 1학기 STL 4월 11일 (6주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
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

	v.push_back("123");
	v.push_back("12345");

	관찰 = false;

	save("main.cpp");
}
