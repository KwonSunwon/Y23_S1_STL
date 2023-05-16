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
#include <ranges>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// 키보드에서 입력한 단어를 사전식 오름차순 정렬하여 출력하라
	set<String> s{ istream_iterator<String>{cin}, {} };
	for (const String& s : s)
		cout << s << endl;

	//save("main.cpp");
}