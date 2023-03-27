//-------------------------------------------------------
// 2023 1�б� STL 3�� 27�� (4�� 1)
//-------------------------------------------------------
// ����(sort) - Callable type(ȣ�Ⱑ��Ÿ��)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <random>
#include <format>
#include <ranges>
#include <algorithm>
#include "save.hpp"

// [����] int 10'000'000 ���� ������ ������ ä���.
// ������������ �����Ѷ�.
// ���� 100���� ȭ�� ����϶�.

class Dog {
public:
	bool operator()(int a, int b) { return a < b; }
};

std::array<int, 10'000'000> numbers;

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 10'000'000 };

bool ���(int a, int b)
{
	return a > b; // ��������
}

int main()
{
	save("main.cpp");

	for (int& num : numbers)
		num = uid(dre);

	// �������� ���� - qsort( c ) �� sort( c++ )
	//std::ranges::sort(numbers); // c++ 20 ���� ��밡��
	std::sort(numbers.begin(), numbers.end(), Dog());

	// ���� 100���� ���
	for (int num : numbers |
		std::views::drop(numbers.size() - 100))
		std::cout << std::format("{:10}", num);
}
