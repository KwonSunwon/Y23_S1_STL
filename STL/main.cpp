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
#include "save.h"
#include "String.h"

using namespace std;

template<>
struct less<String> {
	bool operator()(const String& a, const String& b) const {
		return a.size() < b.size();
	}
};

struct �ҹ��ڿ켱{
	bool operator()(const String& a, const String& b) const {
		if (isupper(a.getString()[0]))
			if(islower(b.getString()[0]))
				return false;
		return true;
	}
};

int main()
{
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	set<String, �ҹ��ڿ켱> s{istream_iterator<String>{in}, {}};
	cout << "���� ����: " << s.size() << endl;

	//save("main.cpp");
}