//-------------------------------------------------------
// 2023 1�б� STL 4�� 11�� (6�� 2)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - vector - dynamic array
// 1. ������ �����ϰ� �������(���Ҵ��� �߻����� �ʵ��� ����)
// 2. push_back ��ſ� emplace_back �� �������
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	extern bool ����;
	���� = true;

 	vector<String> v;
	v.reserve(3);
	v.emplace_back("123"); // emplace�� ���ڴ� "�������� ����"�� �����ؾ� �ȴ�.
	// ���� v.emplae_back(String("123")) ���� �ϸ� �ӽð�ü�� ������ ���̴�.

	v.emplace_back(); // default �����ڰ� ȣ��� ��
	// v.push_back(); // error, push_back�� ��ü�� �޴� ���̱� ������

	���� = false;

	//save("main.cpp");
}
