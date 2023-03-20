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
#include <numeric>
#include "save.hpp"

std::array<int, 260'000> a; // DATA segment

int main()
{
	std::iota(a.begin(), a.end(), 1);

	// ������ 100�������� 100���� ���
	for (int num : a |
		std::views::drop(a.size() - 100)) {
		std::cout << std::format("{:10}", num);
	}

	//save("main.cpp");
}