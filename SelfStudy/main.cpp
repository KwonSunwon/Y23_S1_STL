#include <iostream>
#include <array>
#include <algorithm>
#include <format>
#include <fstream>
#include <string>
#include "String.h"

int main()
{
	//std::array<std::string, 100> a; // 동일하게 동작해야 한다.
	std::array<String, 100> a;

	// [문제] a에 "main.cpp" 단어 100개를 읽어와라.
	std::ifstream in{ "main.cpp" };

	for (int i = 0; i < 100; ++i) {
		in >> a[i];
		std::cout << i << ": " << a[i] << std::endl;
	}

	// 길이 오름차순으로 정렬한 후 출력한다.
	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});

	for (int i = 0; i < 100; ++i) {
		std::cout << a[i] << std::endl;
	}

}
