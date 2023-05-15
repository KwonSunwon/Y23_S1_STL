//-------------------------------------------------------
// 2023 1�б� STL 5�� 15�� (11�� 1)
//-------------------------------------------------------
// Associative �����̳� = set/map (��/���)
// "�̻��� ������ �ٸ���.txt" - 26634
// set�� String�� ��� ����...
// 1. String�� operator<�� ����
// 2. 
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <set>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	ifstream in{ "�̻��� ������ �ٸ���.txt" };

	multiset<String, less<String>> v{ istream_iterator<String>{in}, {} };

	cout << "���� ����: " << v.size() << endl;

	//save("main.cpp");
}