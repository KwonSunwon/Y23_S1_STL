//-------------------------------------------------------
// 2023 1학기 STL 3월 21일 (3주 2)
//-------------------------------------------------------
// STACK의 한계 - 1MB가 default(COMPILER가 코드 생성하지 않는 것 주의)
// STACK의 한계는 경고해주지 않음
// 더 큰 데이터 사용 - DATA와 FreeStore(HEAP)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <numeric>
#include "save.hpp"

// C++ 컴파일러가 값을 결정할 수 있는 순간
// 1. compile-timeh - array<int, 100> ...
// 2. run-time		- new int[100] ...


int main()
{
	int cnt{};
	while (true) {
		int num{ 200'000'000 }; // 800MB
		int* p = new int[num] {};

		// 예외가 발생 --> 자원이 계속 쌓이게 된다

		std::iota(*p, *p + num, 1);

		long long sum{};
		for (int i = 0; i < num; ++i)
			sum += *p + i;

		std::cout << "1부터 " << num << "까지 합계 - " << sum << '\n';
		std::cout << ++cnt << "번 실행" << '\n';

		delete[] p;
	}

	/*std::vector<int>* v{ new std::vector<int>(num) };

	std::iota(v->begin(), v->end(), 1);

	auto sum = std::accumulate(v->begin(), v->end(), 0);
	std::cout << "합계는 " << sum << std::endl;*/

	//save("main.cpp");
}