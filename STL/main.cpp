//-------------------------------------------------------
// 2023 1학기 STL 5월 9일 (10주 2)
//-------------------------------------------------------
// String을 STL 컨테이너로 만들어 간다. - begin(), end()
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

//template<typename Iter, typename t>
//Iter my_find(Iter b, Iter e, t v)
//{
//	while (b != e) {
//		if (*b == v)
//			return b;
//		++b;
//	}
//	return e;
//}

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

int main()
{
	String s{ "Containers - Iterators - Algorithms" };

	auto iter = my_find(s.begin(), s.end(), 's');
	if (iter != s.end())
		cout << distance(s.begin(), iter) + 1 << " 위치에서 발견" << endl;
	else
		cout << "없음" << endl;

	list<int> li{ 1,2,3,4,5,6,7,8,9,10 };
	auto iter2 = my_find(li.begin(), li.end(), 5);
	if (iter2 != li.end())
		cout << distance(li.begin(), iter2) + 1 << " 위치에서 발견" << endl;
	else
		cout << "없음" << endl;

	//save("main.cpp");
}