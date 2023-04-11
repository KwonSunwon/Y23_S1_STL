//-------------------------------------------------------
// 2023 1�б� STL 4�� 11�� (6�� 2)
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
#include <array>
#include <fstream>
#include "save.h"
#include "String.h"

using namespace std;

// [����] "main.cpp"�� �о� ���Ĺ vector�� �����϶�.
// ��ҹ��� �������� ���� ������ ���� �������� ������ �󵵸� ����϶�
//
// a - 10
// b - 12
// ...
// z - 0

int main()
{
	ifstream in{ "main.cpp" };

	array<int, 26> alpha{0};
	char ch;
	while (in >> ch) {
		if (isalpha(ch))
			++alpha[tolower(ch) - 'a'];
	}

	for (int i = 0; i < alpha.size(); ++i) {
		cout << char('a' + i) << " - " << alpha[i] << endl;
	}

	save("main.cpp");
}
