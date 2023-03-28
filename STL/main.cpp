//-------------------------------------------------------
// 2023 1학기 STL 3월 27일 (4주 2)
//-------------------------------------------------------
// 정렬(sort) - Callable type(호출가능타입)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <string>
#include <random>
#include <format>
#include <array>
#include <algorithm>
#include <ranges>
#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uidNum{ 0, 100'000 };
std::uniform_int_distribution uidLen{ 1, 60 };
std::uniform_int_distribution<int> uidName{ 'a', 'z' };

class Dog {
	int num;
	std::string name;

public:
	Dog()
	{
		// n [0, 100'000], name 은 [1, 60]글자
		num = uidNum(dre);
		int len = uidLen(dre);
		for (int i = 0; i < len; ++i)
			name += uidName(dre);
	}
	void show() const
	{
		std::cout << std::format("{:8} - {}", num, name) << '\n';
	}
	bool operator<(const Dog& other) const
	{
		return num < other.num;
	}

	int getNum() const
	{
		return num;
	}
};

// [문제] Dog 객체 100만개를 생성하라.
// num 기준 오름차순으로 정렬하라
// 앞에서부터 100개만 출력하라

std::array<Dog, 1'000'000> dogs;

int main()
{
	/*std::ranges::sort(dogs, [](Dog a, Dog b) {
		return a.getNum() < b.getNum();
		});*/

	/*std::sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {
		return a < b;
		});*/

	std::ranges::sort(dogs, std::less());

	for (const auto& dog : dogs |
		std::views::take(100))
		dog.show();

	save("main.cpp");
}
