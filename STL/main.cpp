//-------------------------------------------------------
// 2023 1�б� STL 5�� 22�� (12�� 1)
//-------------------------------------------------------
// map
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// [����] "�̻��� ������ �ٸ���.txt"�� ���� ���ڿ� ���� Ƚ���� ����϶�.
	// a - 100
	// ...
	// z - 2

	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (!in) exit(0);


	map<char, int> cimap;
	char c;
	while (in >> c) {
		if (isalpha(c))
			cimap[tolower(c)]++;
	}

	//for (auto& [����, ����] : cimap)
	//	cout << ���� << " - " << ���� << endl;

	// [����] ���� ���� ������ ����϶�
	multimap<int, char, greater<int>> icmap; // �׳� map���� �ϸ� ������ ���� ���ڰ� ���� �� ���� �߻�
	for (auto& [����, ����] : cimap)
		icmap.emplace(����, ����);

	for (auto& [����, ����] : icmap)
		cout << ���� << " - " << ���� << endl;

	//vector<pair<char, int>> v{ cimap.begin(), cimap.end() };
	//sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
	//	return a.second > b.second;
	//	});

	//for (const auto& [����, ����] : v)
	//	cout << ���� << " - " << ���� << endl;

	save("main.cpp");
}