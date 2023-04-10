//-------------------------------------------------------
// 2023 1�б� STL 4�� 10�� (6�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <thread>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// ���Ͱ� �޸𸮸� �÷����� ����� �����Ѵ�.
	std::vector<int> v;

	size_t old = v.capacity();
	while (true) {
		v.push_back(1);

		if (old != v.capacity()) { // �뷮�� ��ȭ�� ��
			std::cout << "���� �� - " << v.size() << std::endl;
			std::cout << "�뷮	 - " << v.capacity() << std::endl;
			std::cout << std::endl;
			old = v.capacity();
			// 1�� ����.
			std::this_thread::sleep_for(1s);
		}
	}

	//save("main.cpp");
}
