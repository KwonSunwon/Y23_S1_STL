//-------------------------------------------------------
// 2023 1�б� STL 4�� 11�� (6�� 2)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	extern bool ����;
	���� = true;

 	vector<String> v;

	v.push_back("123");
	v.push_back("12345");

	���� = false;

	save("main.cpp");
}
