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

#include <vector>

using namespace std;

//template<typename T>
//void reverse_print(span<T> s)
//{
//	for(auto p = s.rbegin(); p != s.rend(); ++p)
//		cout << *p << ' ';
//}

template<typename T>
void showCategory(T iter)
{
	cout << typeid(T::iterator_category).name() << endl;
}

int main()
{
	String s{ "1234567890" };

	// s를 역방향으로 출력하시오
	//for (auto p = s.end(); p != s.begin();)
	//	cout << *--p << ' ';
	//cout << endl;

	//span<char> sp{ s.begin(), s.end() };
	//for(auto p = sp.rbegin(); p != sp.rend(); ++p)
	//	cout << *p << ' ';
	//cout << endl;

	//reverse_print(span<char>(s));

	// STL 컨테이너라면 rbegin(), rend()도 제공할 수 있다.
	//for (auto p = s.rbegin(); p != s.rend(); ++p)
	//	cout << *p << ' ';
	//cout << endl;

	// STL 컨테이너라면 begin(), end()를 class로 코딩해야한다.
	//for(auto p = s.begin(); p != s.end(); ++p)
	//	cout << *p << ' ';
	//cout << endl;

	// s가 제공하는 반복자가 random_access_iterator_tag가 되도록 하려면?
	showCategory(s.begin());
	cout << typeid(String_iterator::iterator_category).name() << endl;

	//save("main.cpp");
}