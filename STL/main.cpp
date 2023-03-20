//-------------------------------------------------------
// 2023 1�б� STL 3�� 20�� (3�� 1)
//-------------------------------------------------------
// STACK�� �Ѱ� - 1MB�� default(COMPILER�� �ڵ� �������� �ʴ� �� ����)
// �� ū ������ ��� - DATA�� FreeStore(HEAP)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <format>
#include <ranges> // C++20
#include "save.hpp"

std::array<int, 1'990'000'000 / sizeof(int)> a{ 1 }; // DATA segment, ������������ a; ��� ���� ���� a{}; �� ����.
// 1.85GB - ���� ������ ũ��

int main()
{
	for (int num : a |
		std::views::take(100)) {
		std::cout << std::format("{:10}", num);
	}

	save("main.cpp");
}