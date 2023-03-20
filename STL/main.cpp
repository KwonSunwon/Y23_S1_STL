//-------------------------------------------------------
// 2023 1학기 STL 3월 20일 (3주 1)
//-------------------------------------------------------
// STACK의 한계 - 1MB가 default(COMPILER가 코드 생성하지 않는 것 주의)
// STACK의 한계는 경고해주지 않음
// 더 큰 데이터 사용 - DATA와 FreeStore(HEAP)
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include "save.hpp"

// [문제] 사용자가 입력한 숫자만큼 int를 저장할 메모리를 생성하라
// 값을 1부터 시작하는 정수롤 채워나가라
// 핪계를 화면에 출력하라
// 예) 10을 입력
// -> int 10개 공간확보 -> 1 2 3 4 5 6 7 8 9 10
// 합계는 55

int main()
{
	std::cout << "생성할 int 개수: ";
	int num;
	std::cin >> num;

	std::vector<int>* v{ new std::vector<int>(num) };

	std::iota(v->begin(), v->end(), 1);

	auto sum = std::accumulate(v->begin(), v->end(), 0);
	std::cout << "합계는 " << sum << std::endl;


	//save("main.cpp");
}