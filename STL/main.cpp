//-------------------------------------------------------
// 2023 1�б� STL 5�� 9�� (10�� 2)
//-------------------------------------------------------
// String�� STL �����̳ʷ� ����� ����. - begin(), end()
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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
	String s{ "���� ������ ����ǳ���?" };
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