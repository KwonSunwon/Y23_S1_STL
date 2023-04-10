//-------------------------------------------------------
// 2023 1�б� STL 4�� 10�� (6�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << sizeof(v) << std::endl;
	std::cout << v.size() << std::endl;		// 1 ���
	std::cout << v.data() << std::endl;		// 2 ���
	std::cout << v.capacity() << std::endl; // 3 ���

	v.push_back(11);
	std::cout << v.size() << std::endl;
	std::cout << v.data() << std::endl;
	std::cout << v.capacity() << std::endl;

	save("main.cpp");
}
