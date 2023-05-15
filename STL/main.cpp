//-------------------------------------------------------
// 2023 1학기 STL 5월 15일 (11주 1)
//-------------------------------------------------------
// Associative 컨테이너 = set/map (상등서/동등성)
// "이상한 나라의 앨리스.txt" - 26634
// set에 String을 담기 위해...
// == set의 정렬기준을 설정하는 방법 ==
// 1. String이 operator<를 제공
// 2. less<String>을 specialization
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <set>
#include "save.h"
#include "String.h"

using namespace std;

// Specialization, 특수화
template<>
struct less<String>{
	bool operator()(const String& a, const String& b) const {
		// 길이순 정렬
		return a.size() < b.size();
	}
};

int main()
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	set<String> s{istream_iterator<String>{in}, {}};
	cout << "읽은 개수: " << s.size() << endl;

	//save("main.cpp");
}