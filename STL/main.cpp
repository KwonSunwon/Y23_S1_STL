//-------------------------------------------------------
// 2023 1�б� STL 5�� 8�� (10�� 1)
//-------------------------------------------------------
// String�� STL �����̳ʷ� ����� ����. - begin(), end()
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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

	// s�� ���������� ����Ͻÿ�
	/*for (auto p = s.end(); p != s.begin();)
		cout << *--p << ' ';
	cout << endl;

	span<char> sp{ s.begin(), s.end() };
	for(auto p = sp.rbegin(); p != sp.rend(); ++p)
		cout << *p << ' ';
	cout << endl;

	reverse_print(span<char>(s));*/

	// STL �����̳ʶ�� rbegin(), rend()�� ������ �� �ִ�.
	for (auto p = s.rbegin(); p != s.rend(); p.operator++())
		cout << p.operator*() << ' ';
	cout << endl;

	//save("main.cpp");
}