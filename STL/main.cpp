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
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

int main()
{
	// 덱의 메모리는 contiguous?
	deque<int> d{ 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < d.size(); ++i)
			cout << addressof(d[i]) << endl;
	// 메모리 주소가 4개씩 연속되어 있다
	
	//save("main.cpp");
}