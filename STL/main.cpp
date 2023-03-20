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
#include <array>
#include "save.hpp"

int main()
{
	std::array<int, 1000> a;
	a[0] = 123;
	a[999] = 456;
	std::cout << a[0] << ", " << a[999] << '\n';
	main();

	save("main.cpp");
}