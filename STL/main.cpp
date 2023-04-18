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

int main()
{
	ifstream in{ "����Ʈ.txt" };
	if (!in) {
		cout << "file open error" << endl;
		return 0;
	}

	list<String> strList{ istream_iterator<String>{in}, {} };

	cout << strList.size() << endl;

	// [����] �Է��� �ܾ �ִ� ��, �ִٸ� �� ��° �ܾ����� ����϶�.
	while (true) {
		cout << "ã�� �ܾ �Է��Ͻÿ�: ";
		String s;
		cin >> s;

		// ã�Ƽ� ���
		auto iter = find(strList.begin(), strList.end(), s);
		if (iter == strList.end()) {
			cout << s << "�� �����ϴ�." << endl;
			continue;
		}
		
		cout << s << "�� ã�ҽ��ϴ� - " << distance(strList.begin(), iter) + 1 << endl;
	}

	save("main.cpp");
}