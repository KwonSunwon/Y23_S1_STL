//-------------------------------------------------------
// 2023 1�б� STL 4�� 4�� (5�� 2)
//-------------------------------------------------------
// Sequence Container - array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

int main()
{
	//std::array<std::string, 100> a; // �����ϰ� �����ؾ� �Ѵ�.
	std::array<String, 100> a;

	// [����] a�� "main.cpp" �ܾ� 100���� �о�Ͷ�.
	std::ifstream in{ "main.cpp" };

	for (int i = 0; i < 100; ++i) {
		in >> a[i];
	}

	// ���� ������������ ������ �� ����Ѵ�.
	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});

	for (int i = 0; i < 100; ++i) {
		std::cout << a[i] << std::endl;
	}

	save("main.cpp");
}
