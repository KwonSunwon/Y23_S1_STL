//-------------------------------------------------------
// 2023 1�б� STL 4�� 18�� (7�� 2)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - deque(��)
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <deque>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

int main()
{
	deque<String> d{ "1", "2", "3" };

	���� = true;
	// v�տ� 0�� �߰��Ͻÿ�
	d.emplace(d.begin(), "0");
	���� = false;

	for (const String& s : d)
		cout << s << " ";
	cout << endl;

	save("main.cpp");
}