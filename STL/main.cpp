//-------------------------------------------------------
// 2023 1�б� STL 4�� 24�� (8�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// span, mdspan
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <span>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

void print(int[]); // void print(int*)

int main()
{
	int a[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	print(a);  // a�� ���� ȭ�鿡 ���

	//save("main.cpp");
}

void print(int a[])
{
	//for (int i = 0; i < ???)  // ���� ������ ���� �Ѿ���� �ʴ´�.
	for (int i = 0 ; i < 20; ++i)
		cout << a[i] << ' ';
	cout << endl;
}