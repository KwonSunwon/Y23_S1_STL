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
#include <ranges>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// [����] "�̻��� ������ �ٸ���.txt"�� ���� �ܾ�� ���� Ƚ���� ����϶�.
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (!in) exit(0);

	map<String, int> Simap;

	String word;
	while (in >> word)
		Simap[word]++;

	/*for (auto& [word, count] : Simap)
		cout << word << " - " << count << endl;*/

	// ���� ���� �ܾ���� ������������ ����϶�.
	/*multimap<int, String, greater<int>> iSmap;
	for (auto& [word, count] : Simap)
		iSmap.emplace(count, word);

	for (const auto& [count, word] : iSmap | views::take(100))
		cout << count << "\t- " << word << endl;*/

	multimap<int, String> iSmap;
	for (auto& [word, count] : Simap)
		iSmap.emplace(count, word);

	for (const auto& [count, word] : iSmap | views::reverse | views::take(100))
		cout << count << "\t- " << word << endl;

	//save("main.cpp");
}