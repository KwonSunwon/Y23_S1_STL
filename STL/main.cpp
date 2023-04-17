//-------------------------------------------------------
// 2023 1학기 STL 4월 17일 (7주 1)
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
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

int main()
{
	//관찰 = true;
	vector<String> v{ "1", "2", "3", "4", "5" };

	// v에서 "3"을 제거하라
	//v.erase(remove(v.begin(), v.end(), 3), v.end());
	erase(v, "3");

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;

	//save("main.cpp");
}
