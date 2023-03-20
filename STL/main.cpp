//-------------------------------------------------------
// 2023 1�б� STL 3�� 20�� (3�� 1)
//-------------------------------------------------------
// STACK�� �Ѱ� - 1MB�� default(COMPILER�� �ڵ� �������� �ʴ� �� ����)
// STACK�� �Ѱ�� ��������� ����
// �� ū ������ ��� - DATA�� FreeStore(HEAP)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include "save.hpp"

// [����] ����ڰ� �Է��� ���ڸ�ŭ int�� ������ �޸𸮸� �����϶�
// ���� 1���� �����ϴ� ������ ä��������
// �D�踦 ȭ�鿡 ����϶�
// ��) 10�� �Է�
// -> int 10�� ����Ȯ�� -> 1 2 3 4 5 6 7 8 9 10
// �հ�� 55

int main()
{
	std::cout << "������ int ����: ";
	int num;
	std::cin >> num;

	std::vector<int>* v{ new std::vector<int>(num) };

	std::iota(v->begin(), v->end(), 1);

	auto sum = std::accumulate(v->begin(), v->end(), 0);
	std::cout << "�հ�� " << sum << std::endl;


	//save("main.cpp");
}