//-------------------------------------------------------
// 2023 1�б� STL 4�� 17�� (7�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
// 1. ������ �����ϰ� �������(���Ҵ��� �߻����� �ʵ��� ����)
// 2. push_back ��ſ� emplace_back �� �������
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

int main()
{
	//���� = true;
	vector<String> v{ "1", "2", "4", "5" };

	// "2"�� "4" ���̿� "3"�� ���� �־��
	���� = true;
	v.emplace(v.begin() + 2, "3");
	���� = false;

	for (const String& s: v)
		cout << s << ' ';
	cout << endl;

	//save("main.cpp");
}
