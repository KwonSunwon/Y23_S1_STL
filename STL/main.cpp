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
	// 벡터의 메모리는 contiguous?
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	// v의 메모리가 연속되어 있는지 확인하시오
	if(v.data() == &v[0])
		cout << "두 주소는 같다" << endl;

	for (int i = 0; i < v.size(); ++i)
			cout << addressof(v[i]) << endl;
	
	//save("main.cpp");
}