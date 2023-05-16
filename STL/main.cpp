//-------------------------------------------------------
// 2023 1�б� STL 5�� 16�� (11�� 2)
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

	// [����] String�� �Է¹޾� �� String�� �� set�� ���Ҹ� ����϶�
	while (true) {
		cout << "���ڸ� �Է��ϼ���: ";
		String word;
		cin >> word;

		cout << word << "�� ���Ե� String�Դϴ�" << endl;
		// string���� ��ȯ���� �ʰ�
		for (auto str : s) {
			auto iter = search(str.begin(), str.end(), word.begin(), word.end());
			if (iter != str.end())
				cout << str << endl;
		}
		cout << endl;
	}

	//save("main.cpp");
}