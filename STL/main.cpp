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

#include "save.hpp"

class Dog {
	// 5byte�� ���� �� ������ �ӵ��� ���� 8byte ����
	// �� ���� �е�
	char c;
	int n;

public:
	Dog() {}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog)
	{
		return os << "���� - " << dog.c << ", ���� - " << dog.n;
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog)
	{
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}
};

// [����] Dog 1000 ��ü�� ���� "Dog õ����"�� binary mode�� �� ���Ͽ�
// write �Լ��� �޸� �״�� ��ϵǾ� �ִ�.
// Dog�� ������ cout���� ȭ�鿡 ����϶�.

int main()
{
	std::ifstream in{ "Dog õ����", std::ios::binary };

	if (!in)
		return 0;

	Dog dog;
	int cnt{};
	while (in >> dog) {
		std::cout << dog << '\n';
		++cnt;
	}

	std::cout << "��� " << cnt << "�� ��ü�� ����" << '\n';

	//save("main.cpp");
	git_commit("git_commit() �Լ� ȣ�� �׽�Ʈ");
}