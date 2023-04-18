//-------------------------------------------------------
// 2023 1학기 STL 4월 18일 (7주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - deque(덱)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <deque>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

int main()
{
	deque<String> d{ "1", "2", "3" };

	관찰 = true;
	// v앞에 0을 추가하시오
	d.emplace(d.begin(), "0");
	관찰 = false;

	for (const String& s : d)
		cout << s << " ";
	cout << endl;

	save("main.cpp");
}