//-------------------------------------------------------
// 2023 1학기 STL 3월 13일 (2주 1)
//-------------------------------------------------------
// C++ 복습, template
//-----------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include "save.hpp"

// [문제] main()을 고치지 말고 의도대로 실행되게 하라.
// change() 함수를 한 번만 코딩해서 하라.

class Dog
{
private:
    int num;

public:
    Dog(int n) : num(n) {};
    friend std::ostream& operator<<(std::ostream& os, const Dog& dog)
    {
        return os << dog.num;
    }
};

// template은 선언과 동시에 정의
// template으로 작성된 소스코드는 모두에게 공개되어 있다.
// 컴파일러가 소스코드를 확인하고 만들어내야하기 때문에
template <class T>
void change(T& a, T& b)
{
    T temp{ a };
    a = b;
    b = temp;
}

int main()
{
    {
        int a{ 1 }, b{ 2 };
        change(a, b);
        std::cout << a << ", " << b << '\n';
    }
    {
        Dog a{ 1 }, b{ 2 };
        change(a, b);
        std::cout << a << ", " << b << '\n';
    }

    save("main.cpp");
}
