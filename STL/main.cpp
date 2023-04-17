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
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	
	// [문제] v에서 3을 제거하라.
	// 알고리즘 함수 remove를 사용하면 된다.

	auto iter = remove(v.begin(), v.end(), 3); // 이런 경우에는 auto를 사용한다.
	v.erase(iter, v.end());

	v.erase(remove(v.begin(), v.end(), 3), v.end()); // 그리고 보통은 이렇게 한다.
	// -> erase-remove idiom
	// 근데 매번 이렇게 쓰기 귀찮으니까 C++20 부터는...
	erase(v, 3); // 새로운 전역함수가 제공된다
	// 그런데 이거 벡터에서만 돌아감, 그리고 진짜 전역변수가 아닌 syntactic sugar이다.

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;

	save("main.cpp");
}
