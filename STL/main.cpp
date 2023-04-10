//-------------------------------------------------------
// 2023 1학기 STL 4월 10일 (6주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

// [문제] 키보드에서 단어를 읽어와라
// 오름차순 정렬하라
// 화면에 출력하라

int main()
{
	vector<string> v;

	string s;
	while (cin >> s)
		v.push_back(s); // ctrl + z 탈출

	sort(v.begin(), v.end());

	for (auto& s : v)
		cout << s << endl;

	save("main.cpp");
}
