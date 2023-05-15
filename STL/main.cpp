//-------------------------------------------------------
// 2023 1학기 STL 5월 15일 (11주 1)
//-------------------------------------------------------
// Associative 컨테이너 = set/map (상등서/동등성)
// "이상한 나라의 앨리스.txt" - 26634
// set에 String을 담기 위해...
// 1. String이 operator<를 제공
// 2. 
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <set>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	set<String, less<String>> s{ istream_iterator<String>{in}, {} };
	cout << "읽은 개수: " << s.size() << endl;

	// [문제] 사용자가 입력한 단어가 set에 있는지 있다면 몇 번째 단어인지 출력

	while (true) {
		cout << "찾을 단어를 입력하세요: ";
		String word;
		cin >> word;

		auto iter = s.find(word);
		if(iter != s.end())
			cout << "찾은 단어 위치: " << distance(s.begin(), iter) + 1 << endl;
		else
			cout << "찾지 못했습니다." << endl;
	}

	save("main.cpp");
}