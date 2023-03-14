//-------------------------------------------------------
// 2023 1�б� STL 3�� 14�� (2�� 2)
//-------------------------------------------------------
// ���� ���� �ڷ� �ٷ�� - int
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <array>
#include <iostream>
#include <sstream>

#include "save.hpp"

// [����] ���� "int õ��"�� �ִ� int 1000���� �޸𸮿� �����϶�
// int�� �ؽ�Ʈ �������� �������� �и��Ǿ� ����Ǿ� �ִ�

// contiguous memory(������ ���� �޸�)
// continuous(�ð��� ����)

std::array<int, 1> ga; // DATA
int gn;

int main()
{
    std::array<int, 1'000> a;
    std::cout << sizeof a << '\n'; // STACK
    int n;

    int* pn = new int;

    std::cout << "STACK�� �ִ� a�� ����\t- " << std::addressof(a) << '\n';
    std::cout << "STACK�� �ִ� n�� ����\t- " << std::addressof(n) << '\n';
    std::cout << '\n';

    std::cout << "FreeStore�� ����\t- " << std::addressof(pn) << '\n';
    std::cout << '\n';

    std::cout << "CODE�� �ִ� main\t- " << std::addressof(main) << '\n';
    std::cout << "CODE�� �ִ� save\t- " << std::addressof(save) << '\n';
    std::cout << '\n';

    std::cout << "DATA�� �ִ� ga�� ����\t- " << std::addressof(ga) << '\n';
    std::cout << "DATA�� �ִ� gn�� ����\t- " << std::addressof(gn) << '\n';

    delete (pn);

    //save("main.cpp");
}