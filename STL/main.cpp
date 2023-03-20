//-------------------------------------------------------
// 2023 1학기 STL 3월 20일 (3주 1)
//-------------------------------------------------------
// STACK의 한계 - 1MB가 default(COMPILER가 코드 생성하지 않는 것 주의)
// 더 큰 데이터 사용 - DATA와 FreeStore(HEAP)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <format>
#include <ranges> // C++20
#include <numeric>
#include "save.hpp"

std::array<int, 260'000> a; // DATA segment

int main()
{
	std::iota(a.begin(), a.end(), 1);

	// 마지막 100개전에서 100개만 출력
	for (int num : a |
		std::views::drop(a.size() - 100)) {
		std::cout << std::format("{:10}", num);
	}

	//save("main.cpp");
}