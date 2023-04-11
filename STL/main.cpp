//-------------------------------------------------------
// 2023 1학기 STL 4월 11일 (6주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
// 1. 공간을 예약하고 사용하자(재할당이 발생하지 않도록 주의)
// 2. push_back 대신에 emplace_back 을 사용하자
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include "save.h"
#include "String.h"

using namespace std;

// [문제] "main.cpp"를 읽어 알파뱃만 vector에 저장하라.
// 대소문자 구분하지 말고 다음과 같은 형식으로 문자의 빈도를 출력하라
//
// a - 10
// b - 12
// ...
// z - 0

int main()
{
	ifstream in{ "main.cpp" };

	array<int, 26> alpha{0};
	char ch;
	while (in >> ch) {
		if (isalpha(ch))
			++alpha[tolower(ch) - 'a'];
	}

	for (int i = 0; i < alpha.size(); ++i) {
		cout << char('a' + i) << " - " << alpha[i] << endl;
	}

	save("main.cpp");
}
