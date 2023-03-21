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

// [����] "main.cpp"�� �о� �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ�
// "main_upper.cpp"�� �����϶�.

int main()
{
	save("main.cpp");

	std::ifstream in{ "main.cpp" };
	std::ofstream out{ "main_upper.cpp " };

	std::transform(std::istreambuf_iterator<char>{in}, {},
		std::ostreambuf_iterator<char>{out},
		[](char c) {
			return toupper(c);
		});
}
