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
	set<String, less<String>> s{ istream_iterator<String>{in}, {} };
	cout << "���� ����: " << s.size() << endl;

	// [����] ����ڰ� �Է��� �ܾ set�� �ִ��� �ִٸ� �� ��° �ܾ����� ���

	while (true) {
		cout << "ã�� �ܾ �Է��ϼ���: ";
		String word;
		cin >> word;

		auto iter = s.find(word);
		if(iter != s.end())
			cout << "ã�� �ܾ� ��ġ: " << distance(s.begin(), iter) + 1 << endl;
		else
			cout << "ã�� ���߽��ϴ�." << endl;
	}

	save("main.cpp");
}