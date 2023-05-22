//-------------------------------------------------------
// 2023 1학기 STL 5월 22일 (12주 1)
//-------------------------------------------------------
// map
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
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
	// [문제] "이상한 나라의 앨리스.txt"에 사용된 문자와 사용된 횟수를 출력하라.
	// a - 100
	// ...
	// z - 2

	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (!in) exit(0);


	map<char, int> cimap;
	char c;
	while (in >> c) {
		if (isalpha(c))
			cimap[tolower(c)]++;
	}

	//for (auto& [문자, 개수] : cimap)
	//	cout << 문자 << " - " << 개수 << endl;

	// [문제] 많이 사용된 순서로 출력하라
	multimap<int, char, greater<int>> icmap; // 그냥 map으로 하면 개수가 같은 문자가 있을 때 문제 발생
	for (auto& [문자, 개수] : cimap)
		icmap.emplace(개수, 문자);

	for (auto& [개수, 문자] : icmap)
		cout << 문자 << " - " << 개수 << endl;

	//vector<pair<char, int>> v{ cimap.begin(), cimap.end() };
	//sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
	//	return a.second > b.second;
	//	});

	//for (const auto& [문자, 개수] : v)
	//	cout << 문자 << " - " << 개수 << endl;

	save("main.cpp");
}