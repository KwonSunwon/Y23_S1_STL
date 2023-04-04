//-------------------------------------------------------
// 2023 1�б� STL 4�� 4�� (5�� 2)
//-------------------------------------------------------
// Sequence Container - array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"

int main()
{
	std::array<int, 10> a{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// [����] a�� ��� �����͸� ȭ�鿡 ����϶�
	for (auto p = a.begin(); p != a.end(); ++p) // � STL �ڷᱸ���� ���� ���� ��� ���� -> ǥ��
		std::cout << *p << ' ';
	std::cout << std::endl;

	for (int i = 0; i < a.size(); ++i) // array �ڷᱸ���� ������
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	save("main.cpp");
}
