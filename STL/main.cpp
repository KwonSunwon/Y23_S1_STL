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
#include <string>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

void print(span<char>);

int main()
{
	string a = "hello world";

	print(a);

	const char* p = "hello world";
	print(span<char>((char*)p, (char*)p + strlen(p)));

	//save("main.cpp");
}

void print(span<char> s)
{
	for(auto p = s.rbegin(); p != s.rend(); ++p)
		cout << *p << ' ';
	cout << endl;
}