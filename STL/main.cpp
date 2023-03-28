//-------------------------------------------------------
// 2023 1�б� STL 3�� 27�� (4�� 2)
//-------------------------------------------------------
// ����(sort) - Callable type(ȣ�Ⱑ��Ÿ��)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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
		// n [0, 100'000], name �� [1, 60]����
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

// [����] Dog ��ü 100������ �����϶�.
// num ���� ������������ �����϶�
// �տ������� 100���� ����϶�

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
