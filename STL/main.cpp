//-------------------------------------------------------
// 2023 1학기 STL 3월 14일 (2주 2)
//-------------------------------------------------------
// 많은 수의 자료 다루기 - int
// int 한 개를 저장하는 데 필요한 메모리 공간은?
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <array>
#include <iostream>
#include <sstream>

#include "save.hpp"

// [문제] 파일 "int 천개"에 있는 int 1000개를 메모리에 저장하라
// int는 텍스트 형식으로 공백으로 분리되어 저장되어 있다

// contiguous memory(공간적 연속 메모리)
// continuous(시간적 연속)

// DATA와 STACK 공간은 떨어져 있다
std::array<int, 1'000> ga; // DATA
int gn;

int main()  // CODE/TEXT SEGMENT -> DATA와 위치가 가까움
{
    std::array<int, 1'000> a;
    std::cout << sizeof a << '\n'; // STACK
    int n;

    std::cout << "STACK에 있는 a의 번지\t- " << std::addressof(a) << '\n';
    std::cout << "STACK에 있는 n의 번지\t- " << std::addressof(n) << '\n';
    std::cout << '\n';

    int* p = new int {};
    std::cout << "FreeStore의 있는 번지\t- " << p << '\n'; // 포인터 주소가 가리키는 freestore 데이터의 주소
    //std::cout << "FreeStore의 있는 번지\t- " << std::addressof(p) << '\n'; // 포인터의 주소
    std::cout << '\n';

    std::cout << "CODE에 있는 main\t- " << std::addressof(main) << '\n';
    std::cout << "CODE에 있는 save\t- " << std::addressof(save) << '\n';
    std::cout << '\n';

    // DATA 영역은 두 가지로 나뉜다
    std::cout << "DATA에 있는 ga의 번지\t- " << std::addressof(ga) << '\n';
    std::cout << "DATA에 있는 gn의 번지\t- " << std::addressof(gn) << '\n';

    save("main.cpp");
}