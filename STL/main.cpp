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
#include "save.hpp"

std::array<int, 1'990'000'000 / sizeof(int)> a{ 1 }; // DATA segment, 전역공간에서 a; 라고 쓰는 것은 a{}; 과 같다.
// 1.85GB - 실행 파일의 크기

int main()
{
	for (int num : a |
		std::views::take(100)) {
		std::cout << std::format("{:10}", num);
	}

	save("main.cpp");
}