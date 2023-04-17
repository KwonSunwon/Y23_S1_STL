//-------------------------------------------------------
// 2023 1학기 STL 4월 17일 (7주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
// 1. 사용할 공간을 예약하고 쓰자 - reserve()
// 2. push_back보다는 emplace_back을 사용한다
// 3. 중간에 원소를 삽입하거나 삭제를 자주 해야 한다면 다른 컨테이너를 사용
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

int main()
{
	//관찰 = true;
	vector<String> v{ "1", "2", "4", "5" };

	// "2"와 "4" 사이에 "3"을 끼워 넣어라
	관찰 = true;
	v.emplace(v.begin() + 2, "3");
	관찰 = false;

	for (const String& s: v)
		cout << s << ' ';
	cout << endl;

	//save("main.cpp");
}
