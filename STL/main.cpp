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
	// ���� �޸𸮴� contiguous?
	deque<int> d{ 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < d.size(); ++i)
			cout << addressof(d[i]) << endl;
	// �޸� �ּҰ� 4���� ���ӵǾ� �ִ�
	
	//save("main.cpp");
}