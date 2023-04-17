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
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	vector<int> v(100);
	iota(v.begin(), v.end(), 1);

	// [����] v���� Ȧ���� �����϶�
	// remvoe_if �� �����ϴ�
	// ������ �Ǵ��ϴ� callable = predicate

	v.erase(remove_if(v.begin(), v.end(), [](int val) { // ���⿡�� const int& �� �ʿ����...
		return val & 1; // val % 2 ������ ������ ������ ��� ����, val & 1 ��Ʈ���� - ���� ������ ��Ʈ�� 1�̸� Ȧ��
		}), v.end());

	erase_if(v, [](int val) {
		return val & 1;
		});
	
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;

	save("main.cpp");
}
