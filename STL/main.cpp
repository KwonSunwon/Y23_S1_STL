//-------------------------------------------------------
// 2023 1학기 STL 3월 27일 (4주 1)
//-------------------------------------------------------
// 정렬(sort) - Callable type(호출가능타입)
// 1. 함수(함수 포인터)
// 2. 함수 객체(함수호출 연산자()를 오버로딩한 클래스)
// 3. 람다(이름없는 함수)
// 4. 멤버함수 포인터
// 
// 전체를 추상화 한(대표하는) 클래스 -> function
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <functional>
#include "save.h"

// [문제] 게임의 버튼에 할당된 기능을 바꾼다

void jump()
{
	std::cout << "점프" << '\n';
}
void slide()
{
	std::cout << "슬라이드" << '\n';
}

int main()
{
	save("main.cpp");

	//std::function<void(void)> aKey = jump;
	void(*aKey)(void) = jump; // == auto aKey = jump;
	auto lKey = slide;

	while (true) {
		// 키 설명: a/l 점프/슬라이드, o 옵션, q 끝내기
		std::cout << "키를 누르세요(a, l, o, q): ";
		char c;
		std::cin >> c;
		
		switch (c) {
		case 'a':
			aKey();
			break;
		case 'l':
			lKey();
			break;
		case 'o':
			if (aKey == jump) {
				aKey = slide;
				lKey = jump;
			}
			else {
				aKey = jump;
				lKey = slide;
			}
			break;
		case 'q':
			return 0;
		}
	}
}
