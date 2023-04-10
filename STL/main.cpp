//-------------------------------------------------------
// 2023 1�б� STL 4�� 10�� (6�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

// [����] Ű���忡�� �ܾ �о�Ͷ�
// �������� �����϶�
// ȭ�鿡 ����϶�

int main()
{
	vector<string> v;

	string s;
	while (cin >> s)
		v.push_back(s); // ctrl + z Ż��

	sort(v.begin(), v.end());

	for (auto& s : v)
		cout << s << endl;

	save("main.cpp");
}
