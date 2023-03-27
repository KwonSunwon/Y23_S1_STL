//-------------------------------------------------------
// 2023 1�б� STL 3�� 27�� (4�� 1)
//-------------------------------------------------------
// ����(sort) - Callable type(ȣ�Ⱑ��Ÿ��)
// 1. �Լ�(�Լ� ������)
// 2. �Լ� ��ü(�Լ�ȣ�� ������()�� �����ε��� Ŭ����)
// 3. ����(�̸����� �Լ�)
// 4. ����Լ� ������
// 
// ��ü�� �߻�ȭ ��(��ǥ�ϴ�) Ŭ���� -> function
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <functional>
#include "save.h"

// [����] ������ ��ư�� �Ҵ�� ����� �ٲ۴�

void jump()
{
	std::cout << "����" << '\n';
}
void slide()
{
	std::cout << "�����̵�" << '\n';
}

int main()
{
	save("main.cpp");

	//std::function<void(void)> aKey = jump;
	void(*aKey)(void) = jump; // == auto aKey = jump;
	auto lKey = slide;

	while (true) {
		// Ű ����: a/l ����/�����̵�, o �ɼ�, q ������
		std::cout << "Ű�� ��������(a, l, o, q): ";
		char c;
		std::cin >> c;
		
		switch (c) {
		case 'a':
			aKey();
			break;
		case 'l':
			lKey();
			break;
		case 'o':
			if (aKey == jump) {
				aKey = slide;
				lKey = jump;
			}
			else {
				aKey = jump;
				lKey = slide;
			}
			break;
		case 'q':
			return 0;
		}
	}
}
