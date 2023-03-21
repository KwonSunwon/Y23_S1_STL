//-------------------------------------------------------
// 2023 1�б� STL 3�� 21�� (3�� 2)
//-------------------------------------------------------
// ���� ����
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.hpp"

// [����] "main.cpp"�� �ִ� ���ڸ� '*'�� ��ȯ�Ͽ� ȭ�鿡 ����϶�

int main()
{
	save("main.cpp");

	std::ifstream in{ "main.cpp" };

	std::transform(std::istreambuf_iterator<char>{in}, {},
		std::ostreambuf_iterator<char>{std::cout},
		[](char c) {
			return isdigit(c) ? '*' : c;
		});
}
