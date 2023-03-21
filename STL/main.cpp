//-------------------------------------------------------
// 2023 1�б� STL 3�� 21�� (3�� 2)
//-------------------------------------------------------
// STACK�� �Ѱ� - 1MB�� default(COMPILER�� �ڵ� �������� �ʴ� �� ����)
// STACK�� �Ѱ�� ��������� ����
// �� ū ������ ��� - DATA�� FreeStore(HEAP)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <numeric>
#include "save.hpp"

// [����] ����ڰ� �Է��� ���ڸ�ŭ int�� ������ �޸𸮸� �����϶�
// ���� 1���� �����ϴ� ������ ä��������
// �D�踦 ȭ�鿡 ����϶�
// �� ������ �ݺ��϶�

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

		std::cout << "1���� " << num << "���� �հ� - " << sum << '\n';
		std::cout << ++cnt << "�� ����" << '\n';
	}

	/*std::vector<int>* v{ new std::vector<int>(num) };

	std::iota(v->begin(), v->end(), 1);

	auto sum = std::accumulate(v->begin(), v->end(), 0);
	std::cout << "�հ�� " << sum << std::endl;*/

	//save("main.cpp");
}