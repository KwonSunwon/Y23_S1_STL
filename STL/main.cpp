//-------------------------------------------------------
// 2023 1�б� STL 4�� 4�� (5�� 2)
//-------------------------------------------------------
// Sequence Container - array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"

// Containers are objects that store other objects.

int main()
{
	std::array<int, 10> a{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// [����] a�� ��� �����͸� ȭ�鿡 ����϶�
	std::array<int, 10>::iterator p = a.begin();

	save("main.cpp");
}

// Seqeunce Container 
// array
// vector
// deque
// forward-list
// list
// - ���ϴ� ��ġ�� �ٷ� Read & Write 

// Associative Container - O(logN)
// Unordered Associative Container - O(1)

// Iterator