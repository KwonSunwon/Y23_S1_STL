//-------------------------------------------------------
// 2023 1�б� STL 5�� 23�� (12�� 2)
//-------------------------------------------------------
// unordered associative containers - �������� ���� �����̳�
// 1. �������ٴ� ���� ����
// 2. �޸� ������ ȭ�鿡 ����Ѵ�
// 3. String�� ���⿡ ���ҷ� �����������?
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <unordered_set>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	unordered_set<int> us = { 4, 1, 3, 2 };

	for (int n : us)
		cout << n << " ";

	save("main.cpp");
}