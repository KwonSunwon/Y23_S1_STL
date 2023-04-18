//-------------------------------------------------------
// 2023 1�б� STL 4�� 18�� (7�� 2)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - deque(��)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

class Test {
	char x[1024];
};

// [����] � �����̳ʰ� Test��ü(1024byte)�� ���� ���� ���� �� �ֳ�?
// vector, deque, list
// x86 ȯ�濡�� ��
// ���� �ٸ� �����̳ʸ� ������ ���� �۾��� ������ ���� ���� ��ġ��ũ��� �Ѵ�

// int
// vector - 136,216,567
// deque  - 268,435,452
// list	  -  84,053,312

// Test(1024byte)
// vector -   699,913
// deque  - 1,982,426
// list   - 1,876,889

int main()
{
	list<Test> v;

	try {
		while (true) {
			v.emplace_back();
		}
	}
	catch(exception& e) {
		cout << "�޸� �� - " << e.what() << endl;
		cout << "Ȯ���� int �� - " << v.size() << endl;
	}

	save("main.cpp");
}