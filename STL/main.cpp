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
#include <ranges>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// Ű���忡�� �Է��� �ܾ ������ �������� �����Ͽ� ����϶�
	set<String> s{ istream_iterator<String>{cin}, {} };
	for (const String& s : s)
		cout << s << endl;

	//save("main.cpp");
}