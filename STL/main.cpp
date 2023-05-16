//-------------------------------------------------------
// 2023 1학기 STL 5월 16일 (11주 2)
//-------------------------------------------------------
// map
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <map>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// 게임회사, 출시작들
	map<String, list<String>> game{
		{"펄 어비스", {"검은사막", "붉은사막", "도깨비" }},
		{"베데스다", {"폴아웃", "엘더스크롤", "스타필드", "터미네이터"}},
	};

	cout << "맵의 원소 수 - " << game.size() << endl;

	for (const auto& [회사, 게임들] : game) {
		cout << 회사 << " - ";
		for (const String& 게임 : 게임들)
			cout << 게임 << " ";
		cout << endl;
	}

	//save("main.cpp");
}