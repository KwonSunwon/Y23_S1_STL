//-------------------------------------------------------
// 2023 1�б� STL 3�� 14�� (2�� 2)
//-------------------------------------------------------
// ���� ���� �ڷ� �ٷ�� - int
// int �� ���� �����ϴ� �� �ʿ��� �޸� ������?
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

// DATA�� STACK ������ ������ �ִ�
std::array<int, 1'000> ga; // DATA
int gn;

int main()  // CODE/TEXT SEGMENT -> DATA�� ��ġ�� �����
{
    std::array<int, 1'000> a;
    std::cout << sizeof a << '\n'; // STACK
    int n;

    std::cout << "STACK�� �ִ� a�� ����\t- " << std::addressof(a) << '\n';
    std::cout << "STACK�� �ִ� n�� ����\t- " << std::addressof(n) << '\n';
    std::cout << '\n';

    int* p = new int {};
    std::cout << "FreeStore�� �ִ� ����\t- " << p << '\n'; // ������ �ּҰ� ����Ű�� freestore �������� �ּ�
    //std::cout << "FreeStore�� �ִ� ����\t- " << std::addressof(p) << '\n'; // �������� �ּ�
    std::cout << '\n';

    std::cout << "CODE�� �ִ� main\t- " << std::addressof(main) << '\n';
    std::cout << "CODE�� �ִ� save\t- " << std::addressof(save) << '\n';
    std::cout << '\n';

    // DATA ������ �� ������ ������
    std::cout << "DATA�� �ִ� ga�� ����\t- " << std::addressof(ga) << '\n';
    std::cout << "DATA�� �ִ� gn�� ����\t- " << std::addressof(gn) << '\n';

    save("main.cpp");
}