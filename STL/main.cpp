//-------------------------------------------------------
// 2023 1학기 STL 4월 17일 (7주 1)
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
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	vector<int> v(100);
	iota(v.begin(), v.end(), 1);

	// [문제] v에서 홀수를 제거하라
	// remvoe_if 로 가능하다
	// 조건을 판단하는 callable = predicate

	v.erase(remove_if(v.begin(), v.end(), [](int val) { // 여기에는 const int& 가 필요없어...
		return val & 1; // val % 2 나머지 연산은 굉장히 비싼 연산, val & 1 비트연산 - 제일 오른쪽 비트가 1이면 홀수
		}), v.end());

	erase_if(v, [](int val) {
		return val & 1;
		});
	
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;

	save("main.cpp");
}
