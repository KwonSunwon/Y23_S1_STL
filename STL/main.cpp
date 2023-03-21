//-------------------------------------------------------
// 2023 1�б� STL 3�� 21�� (3�� 2)
//-------------------------------------------------------
// �� ū ������ ��� - DATA�� FreeStore(HEAP)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <memory>
#include "save.hpp"

class Dog {
public:
	Dog() { std::cout << "����" << '\n'; }
	~Dog() { std::cout << "�Ҹ�" << '\n'; }
};

void f();

int main()
{
	save("main.cpp");

	int cnt{};
	while (true) {
		try {
			new char[1'000'000'000];
		}
		catch ( std::exception& e ) {
			std::cout << e.what() << '\n';
			return 0;
		}
		std::cout << ++cnt << " �Ҵ� ����" << "\n";
	}
}

void f()
{
	// ������ ���� ���ƾ� �� ��
	// 2. *(raw pointer)�� ���� �� �� -> smart pointer�� ����϶�
	//Dog* p = new Dog;

	// ���ܰ� �߻��ϴ��� STACK�� ������ ������ü�� �Ҹ���� �����Ѵ�.
	// -> STACK unwinding(OS ���� ����)
	std::unique_ptr<Dog> p{ new Dog };	// RAII
	std::unique_ptr <Dog[]> pp{ new Dog[5] };	// RAII

	throw 1;
}