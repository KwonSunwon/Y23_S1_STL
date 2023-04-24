//-------------------------------------------------------
// 2023 1�б� STL 4�� 24�� (8�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - list
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

int main()
{
	list<int> a{ 1, 3, 4, 9, 5, 7 };
	list<int> b{ 4, 10, 2, 4, 4, 8, 6 };

	// a�� b�� merge�϶�
	a.merge(b);

	for (auto& n : a)
		cout << n << ' ';
	cout << endl;

	for (auto& n : b)
		cout << n << ' ';

	//save("main.cpp");
}