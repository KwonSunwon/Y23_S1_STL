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
#include <string>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

// [����] Ű���忡�� int�� �о��.
// �Է��� ������ �հ�� ����� ����϶�.

int main()
{
	vector<int> v;

	int n;
	while (cin >> n)
		v.push_back(n);

	int sum = accumulate(v.begin(), v.end(), 0);

	cout << "�հ�: " << sum << endl;
	cout << "���: " << static_cast<double>(sum) / v.size() << endl;

	//save("main.cpp");
}
