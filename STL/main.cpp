//-------------------------------------------------------
// 2023 1학기 STL 5월 15일 (11주 1)
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

	// [문제] 문자를 하나 입력받아 그 문자가 들어간 String을 모두 출력하라
	while (true) {
		cout << "문자를 입력하세요: ";
		char c;
		cin >> c;

		cout << c << "가 포함된 String입니다" << endl;
		for (auto str : s) {
			//if (str.getString().contains(c))
			auto it = find(str.begin(), str.end(), c);
			if (it != str.end())
				cout << str << endl;
		}
		cout << endl;
	}

	//save("main.cpp");
}