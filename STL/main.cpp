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
	// ������ �޸𸮴� contiguous?
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	// v�� �޸𸮰� ���ӵǾ� �ִ��� Ȯ���Ͻÿ�
	if(v.data() == &v[0])
		cout << "�� �ּҴ� ����" << endl;

	for (int i = 0; i < v.size(); ++i)
			cout << addressof(v[i]) << endl;
	
	//save("main.cpp");
}