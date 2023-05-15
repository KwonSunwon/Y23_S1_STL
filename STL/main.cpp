//-------------------------------------------------------
// 2023 1학기 STL 5월 15일 (11주 1)
//-------------------------------------------------------
// Associative 컨테이너 = set/map (상등서/동등성)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <set>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	set<int> s{1,3,5,7,9,2,4,6,8,10};

	for (int n : s)
		cout << n << ' ';
	cout << endl;

	//save("main.cpp");
}