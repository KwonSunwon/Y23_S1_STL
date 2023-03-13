//-------------------------------------------------------
// 2023 1�б� STL 3�� 13�� (2�� 1)
//-------------------------------------------------------
// C++ ����, template
//-----------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include "save.hpp"

// [����] main()�� ��ġ�� ���� �ǵ���� ����ǰ� �϶�.
// change() �Լ��� �� ���� �ڵ��ؼ� �϶�.

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

// template�� ����� ���ÿ� ����
// template���� �ۼ��� �ҽ��ڵ�� ��ο��� �����Ǿ� �ִ�.
// �����Ϸ��� �ҽ��ڵ带 Ȯ���ϰ� �������ϱ� ������
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
