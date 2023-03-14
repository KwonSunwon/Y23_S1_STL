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

#include "save.hpp"

class Dog {
	// 5byte로 끝낼 수 있지만 속도를 위해 8byte 저장
	// 빈 공간 패딩
	char c;
	int n;

public:
	Dog() {}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog)
	{
		return os << "글자 - " << dog.c << ", 숫자 - " << dog.n;
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog)
	{
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}
};

// [문제] Dog 1000 객체가 파일 "Dog 천마리"에 binary mode로 연 파일에
// write 함수로 메모리 그대로 기록되어 있다.
// Dog의 정보를 cout으로 화면에 출력하라.

int main()
{
	std::ifstream in{ "Dog 천마리", std::ios::binary };

	if (!in)
		return 0;

	Dog dog;
	int cnt{};
	while (in >> dog) {
		std::cout << dog << '\n';
		++cnt;
	}

	std::cout << "모두 " << cnt << "개 객체를 읽음" << '\n';

	//save("main.cpp");
	git_commit("git_commit() 함수 호출 테스트");
}