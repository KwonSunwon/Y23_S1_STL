//-------------------------------------------------------
// 2023 1학기 STL 4월 24일 (8주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - list
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

int main()
{
	list<int> a{ 1, 3, 4, 9, 5, 7 };
	list<int> b{ 4, 10, 2, 4, 4, 8, 6 };

	// a와 b를 merge하라
	a.merge(b);

	for (auto& n : a)
		cout << n << ' ';
	cout << endl;

	for (auto& n : b)
		cout << n << ' ';

	//save("main.cpp");
}