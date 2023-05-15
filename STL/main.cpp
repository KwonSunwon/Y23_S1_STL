//-------------------------------------------------------
// 2023 1�б� STL 5�� 15�� (11�� 1)
//-------------------------------------------------------
// Associative �����̳� = set/map (��/���)
// "�̻��� ������ �ٸ���.txt" - 26634
// set�� String�� ��� ����...
// == set�� ���ı����� �����ϴ� ��� ==
// 1. String�� operator<�� ����
// 2. less<String>�� specialization
// 3. ȣ�Ⱑ��Ÿ���� ����
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	set<String> s{ istream_iterator<String>{in}, {} };
	cout << "���� ����: " << s.size() << endl;

	// [����] ���ڸ� �ϳ� �Է¹޾� �� ���ڰ� �� String�� ��� ����϶�
	while (true) {
		cout << "���ڸ� �Է��ϼ���: ";
		char c;
		cin >> c;

		cout << c << "�� ���Ե� String�Դϴ�" << endl;
		for (auto str : s) {
			//if (str.getString().contains(c))
			auto it = find(str.begin(), str.end(), c);
			if (it != str.end())
				cout << str << endl;
		}
		cout << endl;
	}

	//save("main.cpp");
}