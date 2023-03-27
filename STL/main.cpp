//-------------------------------------------------------
// 2023 1학기 STL 3월 27일 (4주 1)
//-------------------------------------------------------
// 정렬(sort) - Callable type(호출가능타입)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include "save.hpp"

auto lambda = []() {
	std::cout << "Hello? my name is lambda!" << '\n';
};

class Dog {};
Dog dog;

int main()
{
	// name mangling
	std::cout << typeid(lambda).name() << '\n';

	std::cout << typeid(dog).name() << '\n';

	save("main.cpp");
}
