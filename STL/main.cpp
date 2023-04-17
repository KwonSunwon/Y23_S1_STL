//-------------------------------------------------------
// 2023 1�б� STL 4�� 17�� (7�� 1)
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
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	
	// [����] v���� 3�� �����϶�.
	// �˰��� �Լ� remove�� ����ϸ� �ȴ�.

	auto iter = remove(v.begin(), v.end(), 3); // �̷� ��쿡�� auto�� ����Ѵ�.
	v.erase(iter, v.end());

	v.erase(remove(v.begin(), v.end(), 3), v.end()); // �׸��� ������ �̷��� �Ѵ�.
	// -> erase-remove idiom
	// �ٵ� �Ź� �̷��� ���� �������ϱ� C++20 ���ʹ�...
	erase(v, 3); // ���ο� �����Լ��� �����ȴ�
	// �׷��� �̰� ���Ϳ����� ���ư�, �׸��� ��¥ ���������� �ƴ� syntactic sugar�̴�.

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;

	save("main.cpp");
}
