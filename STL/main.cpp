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

	multiset<String, less<String>> v{ istream_iterator<String>{in}, {} };

	cout << "읽은 개수: " << v.size() << endl;

	//save("main.cpp");
}