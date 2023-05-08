//-------------------------------------------------------
// 2023 1학기 STL 5월 8일 (10주 1)
//-------------------------------------------------------
// String을 STL 컨테이너로 만들어 간다. - begin(), end()
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	String s{ "1234567890" };

	for (auto p = s.begin(); p != s.end(); ++p)
		cout << *p << ' ';
	cout << endl;

	//save("main.cpp");
}