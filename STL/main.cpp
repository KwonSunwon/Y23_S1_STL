//-------------------------------------------------------
// 2023 1학기 STL 5월 16일 (11주 2)
//-------------------------------------------------------
// Associative 컨테이너 = set/map (상등서/동등성)
// "이상한 나라의 앨리스.txt" - 26634
// set에 String을 담기 위해...
// == set의 정렬기준을 설정하는 방법 ==
// 1. String이 operator<를 제공
// 2. less<String>을 specialization
// 3. 호출가능타입을 전달
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <set>
#include <algorithm>
#include <ranges>
#include <random>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// 1부터 100까지 정수를 하나도 빠짐없이 랜덤하게 출력하라.
	vector<int> v;
	//set<int> s;
	
	default_random_engine dre{ random_device()() };
	//uniform_int_distribution<int> uid(1, 45);

	v.resize(45);
	iota(v.begin(), v.end(), 1);


	for (int i = 0; i < 100; ++i) {
		shuffle(v.begin(), v.end(), dre);
		for (int i = 0; i < 6; ++i)
			cout << v[i] << " ";
		cout << endl;
	}

	//while (s.size() != 100){
	//	int n = uid(dre);
	//	if (s.insert(n).second)
	//		cout << n << " ";
	//}

	//save("main.cpp");
}