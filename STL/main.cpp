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
	vector<String> v{ "333", "1", "22", "55555", "4444" };

	// [����] v�� ���� ������������ �����϶�

	sort(v.begin(), v.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});

	for (const String& s : v)
		cout << s << endl;

	save("main.cpp");
}
