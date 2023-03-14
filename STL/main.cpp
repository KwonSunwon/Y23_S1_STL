//-------------------------------------------------------
// 2023 1학기 STL 3월 14일 (2주 2)
//-------------------------------------------------------
// 많은 수의 자료 다루기 - class
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
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
	// 5byte로 끝낼 수 있지만 속도를 위해 8byte 저장
	// 빈 공간 패딩
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
		return os << "글자 - " << dog.c << ", 숫자 - " << dog.n;
	}
};

// [문제] Dog 1000 객체를 파일 "Dog 천마리"를 binary mode로 열고
// 메모리 그대로 파일에 기록하라

int main()
{
	std::array<Dog, 1'000> dogs;

	// std::ofstream out { "Dog 천마리", std::ios::binary };
	// out.write((char*)&dogs, dogs.size() * sizeof(Dog)); // 8000byte로 저장됨

	std::ifstream in{ "Dog 천마리", std::ios::binary };
	in.read((char*)&dogs, dogs.size() * sizeof(Dog));

	for (auto& dog : dogs) {
		std::cout << dog << '\n';
	}

	 save("main.cpp");
}