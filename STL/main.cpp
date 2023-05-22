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
#include <ranges>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// [문제] "이상한 나라의 앨리스.txt"에 사용된 단어와 상용된 횟수를 출력하라.
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (!in) exit(0);

	map<String, int> Simap;

	String word;
	while (in >> word)
		Simap[word]++;

	/*for (auto& [word, count] : Simap)
		cout << word << " - " << count << endl;*/

	// 많이 사용된 단어기준 내림차순으로 출력하라.
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