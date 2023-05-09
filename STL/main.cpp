//-------------------------------------------------------
// 2023 1�б� STL 5�� 9�� (10�� 2)
//-------------------------------------------------------
// String�� STL �����̳ʷ� ����� ����. - begin(), end()
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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