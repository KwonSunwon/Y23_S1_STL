//-------------------------------------------------------
// 2023 1학기 STL 4월 24일 (8주 1)
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
	// in >> String, 
	// friend operator>>(ostream, String)
	// while(in >> String) {}, while((in >> String) == true)

	// [문제] 글자 수가 5인 단어를 "다섯글자.txt" 파일에 저장하라.
	ofstream out{"다섯글자.txt"};

	/*copy_if(strList.begin(), strList.end(), ostream_iterator<String>(out, "\n"), [](const String& s) {
		return s.getSize() == 5;
		});*/
	
	for (String& s : strList) {
			if (s.getSize() == 5)
			out << s << endl;
	}

	//save("main.cpp");
}