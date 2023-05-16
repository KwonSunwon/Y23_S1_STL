//-------------------------------------------------------
// 2023 1학기 STL 5월 16일 (11주 2)
//-------------------------------------------------------
// Associative 컨테이너 = set/map (상등서/동등성)
// "이상한 나라의 앨리스.txt" - 26634
// set에 String을 담기 위해...
// == set의 정렬기준을 설정하는 방법 ==
// 1. String이 operator<를 제공
// 2. less<String>을 specialization
// 3. 호출가능타입을 전달
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	set<String> s{ istream_iterator<String>{in}, {} };
	cout << "읽은 개수: " << s.size() << endl;

	// [문제] String을 입력받아 그 String이 들어간 set의 원소를 출력하라
	while (true) {
		cout << "문자를 입력하세요: ";
		String word;
		cin >> word;

		cout << word << "가 포함된 String입니다" << endl;
		// string으로 변환하지 않고
		for (auto str : s) {
			auto iter = search(str.begin(), str.end(), word.begin(), word.end());
			if (iter != str.end())
				cout << str << endl;
		}
		cout << endl;
	}

	//save("main.cpp");
}