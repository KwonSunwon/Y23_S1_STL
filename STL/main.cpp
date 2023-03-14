//-------------------------------------------------------
// 2023 1�б� STL 3�� 14�� (2�� 2)
//-------------------------------------------------------
// ���� ���� �ڷ� �ٷ�� - class
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <array>
#include <fstream>
#include <iostream>
#include <random>

#include "save.hpp"

std::default_random_engine dre;
std::uniform_int_distribution<int> uidChar{ 'a', 'z' };
std::uniform_int_distribution uidNum{ 1, 10'000 };

class Dog {
	// 5byte�� ���� �� ������ �ӵ��� ���� 8byte ����
	// �� ���� �е�
	char c;
	int n;

public:
	Dog()
	{
		c = uidChar(dre); // ['a', 'z']
		n = uidNum(dre); // [1, 10'000]
	}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog)
	{
		return os << "���� - " << dog.c << ", ���� - " << dog.n;
	}
};

// [����] Dog 1000 ��ü�� ���� "Dog õ����"�� binary mode�� ����
// �޸� �״�� ���Ͽ� ����϶�

int main()
{
	std::array<Dog, 1'000> dogs;

	// std::ofstream out { "Dog õ����", std::ios::binary };
	// out.write((char*)&dogs, dogs.size() * sizeof(Dog)); // 8000byte�� �����

	std::ifstream in{ "Dog õ����", std::ios::binary };
	in.read((char*)&dogs, dogs.size() * sizeof(Dog));

	for (auto& dog : dogs) {
		std::cout << dog << '\n';
	}

	 save("main.cpp");
}