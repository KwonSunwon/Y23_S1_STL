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
#include <thread>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// 벡터가 메모리를 늘려가는 모습을 관찰한다.
	std::vector<int> v;

	size_t old = v.capacity();
	while (true) {
		v.push_back(1);

		if (old != v.capacity()) { // 용량이 변화할 때
			std::cout << "원소 수 - " << v.size() << std::endl;
			std::cout << "용량	 - " << v.capacity() << std::endl;
			std::cout << std::endl;
			old = v.capacity();
			// 1초 쉰다.
			std::this_thread::sleep_for(1s);
		}
	}

	//save("main.cpp");
}
