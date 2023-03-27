//-------------------------------------------------------
// 2023 1학기 STL 3월 27일 (4주 1)
//-------------------------------------------------------
// 정렬(sort) - Callable type(호출가능타입)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <random>
#include <format>
#include <ranges>
#include <algorithm>
#include "save.hpp"

// [문제] int 10'000'000 개를 랜덤한 값으로 채운다.
// 오른차순으로 정렬한라.
// 끝에 100개만 화면 출력하라.

class Dog {
public:
	bool operator()(int a, int b) { return a < b; }
};

std::array<int, 10'000'000> numbers;

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 10'000'000 };

bool 어떻게(int a, int b)
{
	return a > b; // 내림차순
}

int main()
{
	save("main.cpp");

	for (int& num : numbers)
		num = uid(dre);

	// 오름차순 정렬 - qsort( c ) 와 sort( c++ )
	//std::ranges::sort(numbers); // c++ 20 부터 사용가능
	std::sort(numbers.begin(), numbers.end(), Dog());

	// 끝에 100개만 출력
	for (int num : numbers |
		std::views::drop(numbers.size() - 100))
		std::cout << std::format("{:10}", num);
}
