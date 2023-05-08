//-------------------------------------------------------
// 2023 1�б� STL 5�� 8�� (10�� 1)
//-------------------------------------------------------
// String�� STL �����̳ʷ� ����� ����. - begin(), end()
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

//template<typename T>
//void reverse_print(span<T> s)
//{
//	for(auto p = s.rbegin(); p != s.rend(); ++p)
//		cout << *p << ' ';
//}

template<typename Iterator>
void showCategory(Iterator iter)
{
	cout << typeid(Iterator::iterator_category).name() << endl;
}

int main()
{
	String s{ "The Quick Brown Fox Jumps Over The Lazy Dog" };

	// s�� ���������� ����Ͻÿ�
	//for (auto p = s.end(); p != s.begin();)
	//	cout << *--p << ' ';
	//cout << endl;

	//span<char> sp{ s.begin(), s.end() };
	//for(auto p = sp.rbegin(); p != sp.rend(); ++p)
	//	cout << *p << ' ';
	//cout << endl;

	//reverse_print(span<char>(s));

	// STL �����̳ʶ�� rbegin(), rend()�� ������ �� �ִ�.
	//for (auto p = s.rbegin(); p != s.rend(); ++p)
	//	cout << *p << ' ';
	//cout << endl;

	// STL �����̳ʶ�� begin(), end()�� class�� �ڵ��ؾ��Ѵ�.
	//for(auto p = s.begin(); p != s.end(); ++p)
	//	cout << *p << ' ';
	//cout << endl;

	// s�� �����ϴ� �ݺ��ڰ� random_access_iterator_tag�� �ǵ��� �Ϸ���?
	//showCategory(s.begin());

	sort(s.begin(), s.end());

	cout << s << endl;

	//save("main.cpp");
}