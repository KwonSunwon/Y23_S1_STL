//-------------------------------------------------------
// 2023 1학기 STL 5월 8일 (10주 1)
//-------------------------------------------------------
// String을 STL 컨테이너로 만들어 간다. - begin(), end()
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <span>
#include "save.h"
#include "String.h"

using namespace std;

//template<typename T>
//void reverse_print(span<T> s)
//{
//	for(auto p = s.rbegin(); p != s.rend(); ++p)
//		cout << *p << ' ';
//}

int main()
{
	String s{ "1234567890" };

	// s를 역방향으로 출력하시오
	/*for (auto p = s.end(); p != s.begin();)
		cout << *--p << ' ';
	cout << endl;

	span<char> sp{ s.begin(), s.end() };
	for(auto p = sp.rbegin(); p != sp.rend(); ++p)
		cout << *p << ' ';
	cout << endl;

	reverse_print(span<char>(s));*/

	// STL 컨테이너라면 rbegin(), rend()도 제공할 수 있다.
	for (auto p = s.rbegin(); p != s.rend(); p.operator++())
		cout << p.operator*() << ' ';
	cout << endl;

	//save("main.cpp");
}