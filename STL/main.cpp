//-------------------------------------------------------
// 2023 1학기 STL 5월 9일 (10주 2)
//-------------------------------------------------------
// String을 STL 컨테이너로 만들어 간다. - begin(), end()
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <algorithm>
#include "save.h"
#include "String.h"

#include <vector>

using namespace std;

template<typename Iterator>
void showCategory(Iterator iter)
{
	cout << typeid(Iterator::iterator_category).name() << endl;
}

int main()
{
	String s{ "the quick brown fox jumps over the lazy dog" };

	sort(s.begin(), s.end());

	cout << s << endl;

	//save("main.cpp");
}