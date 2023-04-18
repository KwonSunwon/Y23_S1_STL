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

int main()
{
	ifstream in{ "리스트.txt" };
	if (!in) {
		cout << "file open error" << endl;
		return 0;
	}

	list<String> strList{ istream_iterator<String>{in}, {} };

	cout << strList.size() << endl;

	// [문제] 입력한 단어가 있는 지, 있다면 몇 번째 단어인지 출력하라.
	while (true) {
		cout << "찾을 단어를 입력하시오: ";
		String s;
		cin >> s;

		// 찾아서 출력
		auto iter = find(strList.begin(), strList.end(), s);
		if (iter == strList.end()) {
			cout << s << "는 없습니다." << endl;
			continue;
		}
		
		cout << s << "를 찾았습니다 - " << distance(strList.begin(), iter) + 1 << endl;
	}

	save("main.cpp");
}