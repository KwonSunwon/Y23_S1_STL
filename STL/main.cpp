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
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

int main()
{
	ifstream in{ "리스트.txt" };
	list<String> strList{ istream_iterator<String>{in}, {} };

	// [문제] 리스트를 오름차순으로 정렬하시오.

	/*sort(strList.begin(), strList.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});*/
	
	strList.sort([](const String& a, const String& b){
		return a.getString() < b.getString();
		});

	strList.unique();

	// 단어 길이 순으로
	/*strList.sort([](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});*/

	for (String& s : strList)
		cout << s << endl;

	//save("main.cpp");
}