//-------------------------------------------------------
// 2023 1학기 STL 4월 11일 (6주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
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

	// [문제] v를 길이 오름차순으로 정렬하라

	sort(v.begin(), v.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});

	for (const String& s : v)
		cout << s << endl;

	save("main.cpp");
}
