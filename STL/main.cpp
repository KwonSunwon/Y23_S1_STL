//-------------------------------------------------------
// 2023 1�б� STL 3�� 27�� (4�� 1)
//-------------------------------------------------------
// ����(sort) - Callable type(ȣ�Ⱑ��Ÿ��)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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
