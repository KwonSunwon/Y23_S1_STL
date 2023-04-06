#include <iostream>
#include <array>
#include <algorithm>
#include <format>
#include <fstream>
#include <string>
#include "String.h"

int main()
{
	//std::array<std::string, 100> a; // �����ϰ� �����ؾ� �Ѵ�.
	std::array<String, 100> a;

	// [����] a�� "main.cpp" �ܾ� 100���� �о�Ͷ�.
	std::ifstream in{ "main.cpp" };

	for (int i = 0; i < 100; ++i) {
		in >> a[i];
		std::cout << i << ": " << a[i] << std::endl;
	}

	// ���� ������������ ������ �� ����Ѵ�.
	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});

	for (int i = 0; i < 100; ++i) {
		std::cout << a[i] << std::endl;
	}

}
