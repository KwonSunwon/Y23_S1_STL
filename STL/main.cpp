//-------------------------------------------------------
// 2023 1학기 STL 5월 9일 (10주 2)
//-------------------------------------------------------
// String을 STL 컨테이너로 만들어 간다. - begin(), end()
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;

template<class Iter, class Val>
Iter my_find(Iter beg, Iter end, Val val)
{
	while (beg != end) {
		if (*beg == val)
			return beg;
		++beg;
	}
	return end;
}

template<class Iter, class Callable>
Iter my_find_if(Iter beg, Iter end, Callable f)
{
	while (beg != end) {
		if (f(*beg))
			return beg;
		++beg;
	}
	return end;
}

template<class InputIter, class OutputIter2>
void my_copy(InputIter beg, InputIter end, OutputIter2 dest)
{
	while (beg != end) {
		*dest = *beg;
		++beg;
		++dest;
	}
}

int main()
{
	String s{ "여기 내용이 복사되나요?" };
	vector<char> v;
	v.reserve(s.size());

	my_copy(s.begin(), s.end(), back_inserter(v));

	for (char c : v)
		cout << c;
	cout << endl;
	auto p = v.data();
	for (int i = 0; i < s.size(); ++i)
		cout << p[i];

	//save("main.cpp");
}