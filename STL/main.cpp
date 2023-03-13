//-------------------------------------------------------
// 2023 1학기 STL 3월 13일 (2주 1)
//-------------------------------------------------------
// 많은 수의 자료 다루기 - int
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <array>
#include <format>
#include <fstream>
#include <iostream>

#include "save.hpp"

// [문제] 파일 "int 천개"에 있는 int 1000개를 메모리에 저장하라
// int는 텍스트 형식으로 공백으로 분리되어 저장되어 있다

int main()
{
    std::ifstream in { "int 천개" };

    std::array<int, 1000> a; // 앞으로 int[] 사용하지 않는다

    for (int i = 0; i < 1000; ++i) {
        in >> a[i];
    }

    auto p = std::max_element(a.begin(), a.end());
    std::cout << "최댓값 : " << *p << '\n';

    save("main.cpp");
}