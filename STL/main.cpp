//-------------------------------------------------------
// 2023 1�б� STL 4�� 18�� (7�� 2)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - list
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <list>
#include <fstream>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

// [����] "����Ʈ.txt"�� �о� list<String>�� �����϶�.
// ��� �� �ܾ��ΰ� ����϶�.

int main()
{
	ifstream in{ "����Ʈ.txt" };
	if (!in) {
		cout << "file open error" << endl;
		return 0;
	}

	String s;
	list<String> strList;
	while (in >> s)
		strList.emplace_back(s);

	cout << strList.size() << endl;

	for (auto& s : strList)
		cout << s << endl;

	//save("main.cpp");
}