//-------------------------------------------------------
// 2023 1학기 STL 4월 10일 (6주 1)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

// [문제] 키보드에서 int를 읽어라.
// 입력이 끝나면 합계와 평균을 출력하라.

int main()
{
	vector<int> v;

	int n;
	while (cin >> n)
		v.push_back(n);

	int sum = accumulate(v.begin(), v.end(), 0);

	cout << "합계: " << sum << endl;
	cout << "평균: " << static_cast<double>(sum) / v.size() << endl;

	//save("main.cpp");
}
