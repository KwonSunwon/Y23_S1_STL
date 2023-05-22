//-------------------------------------------------------
// 2023 1학기 STL 5월 22일 (12주 1)
//-------------------------------------------------------
// map
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <map>
#include <list>
#include <utility>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// 게임회사, 출시작들
	map<String, list<String>> game{
		{"펄 어비스", { "검은사막", "붉은사막", "도깨비" }},
		{ "베데스다", {"폴아웃", "엘더스크롤", "스타필드", "터미네이터"} },
	};

	//game.insert(pair<String, list<String>> {"라이엇", { "리그오브레전드", "발로란트" }});
	game.insert(make_pair("라이엇", list<String>{ "리그오브레전드", "발로란트" }));

	cout << "맵의 원소 수 - " << game.size() << endl;

	// 맵의 키값을 변경하고 싶다면 extract 멤버를 이용한다.(since C++17)
	auto handle = game.extract("펄 어비스");
	handle.key() = "펄어비스";
	game.insert(move(handle));

	// 회사 하나에 게임을 추가한다.
	//game["라이엇"].push_back("레전드오브룬테라"); // 연관배열(associative array)
	//list<String>& val = game["라이엇"];
	auto& val = game["라이엇"]; // 제대로 알고 사용
	val.insert(val.begin(), "팀파이터");

	//auto it = game.find("라이엇");
	//if (it != game.end())
	//	it->second.push_back("레전드오브룬테라");

	for (const auto& [회사, 게임들] : game) {
		cout << 회사 << " - ";
		for (const String& 게임 : 게임들)
			cout << "\"" << 게임 << "\" ";
		cout << endl;
	}

	save("main.cpp");
}