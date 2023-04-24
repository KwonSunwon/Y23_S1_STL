//-------------------------------------------------------
// 2023 1학기 STL 4월 24일 (8주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - list - 멤버로 작성된 함수들을 활용하라.(sort, merge)
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
	list<int> a{ 1, 3, 9, 5, 7 };
	list<int> b{ 4, 10, 2, 8, 6 };

	// a와 b를 내림차순으로 정렬
	a.sort([](int a, int b) { return a > b; });
	b.sort([](int a, int b) { return a > b; });

	for (auto& n : a)
		cout << n << ' ';
	cout << endl;

	for (auto& n : b)
		cout << n << ' ';
	cout << endl;

	// a와 b를 merge하라
	cout << "merge" << endl;
	a.merge(b, [](int a, int b) {
		return a > b;
		});

	for (auto& n : a)
		cout << n << ' ';
	cout << endl;

	for (auto& n : b)
		cout << n << ' ';
	cout << endl;

	//save("main.cpp");
}