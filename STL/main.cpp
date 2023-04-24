//-------------------------------------------------------
// 2023 1�б� STL 4�� 24�� (8�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - list - ����� �ۼ��� �Լ����� Ȱ���϶�.(sort, merge)
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
	list<int> a{ 1, 3, 9, 5, 7 };
	list<int> b{ 4, 10, 2, 8, 6 };

	// a�� b�� ������������ ����
	a.sort([](int a, int b) { return a > b; });
	b.sort([](int a, int b) { return a > b; });

	for (auto& n : a)
		cout << n << ' ';
	cout << endl;

	for (auto& n : b)
		cout << n << ' ';
	cout << endl;

	// a�� b�� merge�϶�
	cout << "merge" << endl;
	a.merge(b, [](int a, int b) {
		return a > b;
		});

	for (auto& n : a)
		cout << n << ' ';
	cout << endl;

	for (auto& n : b)
		cout << n << ' ';
	cout << endl;

	//save("main.cpp");
}