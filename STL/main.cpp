//-------------------------------------------------------
// 2023 1학기 STL 3월 21일 (3주 2)
//-------------------------------------------------------
// 더 큰 데이터 사용 - DATA와 FreeStore(HEAP)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <memory>
#include "save.hpp"

class Dog {
public:
	Dog() { std::cout << "생성" << '\n'; }
	~Dog() { std::cout << "소멸" << '\n'; }
};

void f();

int main()
{
	save("main.cpp");

	try {
		f();
	}
	catch (int) {
		std::cout << "예외발생" << '\n';
	}
}

void f()
{
	// 앞으로 쓰지 말아야 할 것
	// 2. *(raw pointer)를 쓰지 말 것 -> smart pointer를 사용하라
	//Dog* p = new Dog;

	// 예외가 발생하더라도 STACK에 생성된 지역객체가 소멸됨을 보증한다.
	// -> STACK unwinding(OS 관련 내용)
	std::unique_ptr<Dog> p{ new Dog };	// RAII
	std::unique_ptr <Dog[]> pp{ new Dog[5] };	// RAII

	throw 1;
}