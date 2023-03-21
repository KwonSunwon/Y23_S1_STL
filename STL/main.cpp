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

// [문제] 사용자가 입력한 숫자만큼 int를 저장할 메모리를 생성하라
// 값을 1부터 시작하는 정수롤 채워나가라
// 핪계를 화면에 출력하라
// 이 과정을 반복하라

int main()
{
	int cnt{};
	while (true) {
		int num{ 200'000'000 }; // 800MB

		std::unique_ptr<int> p{ new int[num] {} };
		std::iota(*p, *p + num, 1);

		long long sum{};
		for (int i = 0; i < num; ++i)
			sum += *p + i;

		std::cout << "1부터 " << num << "까지 합계 - " << sum << '\n';
		std::cout << ++cnt << "번 실행" << '\n';
	}

	/*std::vector<int>* v{ new std::vector<int>(num) };

	std::iota(v->begin(), v->end(), 1);

	auto sum = std::accumulate(v->begin(), v->end(), 0);
	std::cout << "합계는 " << sum << std::endl;*/

	//save("main.cpp");
}