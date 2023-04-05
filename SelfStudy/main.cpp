#include <iostream>
#include <array>
#include <algorithm>
#include <format>
#include "String.h"

int main()
{
	extern bool observe;
	observe = true;
	std::array<String, 3> news{ "aaa", "ccc", "bbb"};

	std::sort(news.begin(), news.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});

	for (String& s : news)
		std::cout << s << '\n';
}
