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

// [����] � �����̳ʰ� int�� ���� ���� ���� �� �ֳ�?
// vector, deque, list
// x86 ȯ�濡�� ��
// ���� �ٸ� �����̳ʸ� ������ ���� �۾��� ������ ���� ���� ��ġ��ũ��� �Ѵ�

// vector - 136,216,567
// deque  - 268,435,452
// list	  - 84,053,312

int main()
{
	list<int> v;

	try {
		while (true) {
			v.emplace_back(1);
		}
	}
	catch(exception& e) {
		cout << "�޸� �� - " << e.what() << endl;
		cout << "Ȯ���� int �� - " << v.size() << endl;
	}

	//save("main.cpp");
}