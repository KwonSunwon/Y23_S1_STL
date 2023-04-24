//-------------------------------------------------------
// 2023 1학기 STL 4월 24일 (8주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// span, mdspan
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <span>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

void print(span<int>);

int main()
{
	int a[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	print(a);  // a의 값을 화면에 출력

	//save("main.cpp");
}

void print(span<int> s)
{
	for(int i : s)
		cout << i << ' ';
	cout << endl;
}