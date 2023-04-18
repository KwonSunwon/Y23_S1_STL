//-------------------------------------------------------
// 2023 1학기 STL 4월 18일 (7주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - list
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <list>
#include <fstream>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

// [문제] "리스트.txt"를 읽어 list<String>에 저장하라.
// 모두 몇 단어인가 출력하라.

int main()
{
	ifstream in{ "리스트.txt" };
	if (!in) {
		cout << "file open error" << endl;
		return 0;
	}

	String s;
	list<String> strList;
	while (in >> s)
		strList.emplace_back(s);

	cout << strList.size() << endl;

	for (auto& s : strList)
		cout << s << endl;

	//save("main.cpp");
}