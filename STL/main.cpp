//-------------------------------------------------------
// 2023 1학기 STL 4월 18일 (7주 2)
// 4월 25일 - (8주 2) 중간시험
//-------------------------------------------------------
// Sequence Container - deque(덱)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

class Test {
	char x[1024];
};

// [문제] 어떤 컨테이너가 Test객체(1024byte)를 가장 많이 담을 수 있나?
// vector, deque, list
// x86 환경에서 비교
// 서로 다른 컨테이너를 가지고 같은 작업을 수행해 보는 것을 벤치마크라고 한다

// int
// vector - 136,216,567
// deque  - 268,435,452
// list	  -  84,053,312

// Test(1024byte)
// vector -   699,913
// deque  - 1,982,426
// list   - 1,876,889

int main()
{
	list<Test> v;

	try {
		while (true) {
			v.emplace_back();
		}
	}
	catch(exception& e) {
		cout << "메모리 고갈 - " << e.what() << endl;
		cout << "확보한 int 수 - " << v.size() << endl;
	}

	save("main.cpp");
}