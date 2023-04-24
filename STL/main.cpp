//-------------------------------------------------------
// 2023 1�б� STL 4�� 24�� (8�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// Sequence Container - list
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

int main()
{
	ifstream in{ "����Ʈ.txt" };
	list<String> strList{ istream_iterator<String>{in}, {} }; 
	// in >> String, 
	// friend operator>>(ostream, String)
	// while(in >> String) {}, while((in >> String) == true)

	// [����] ���� ���� 5�� �ܾ "�ټ�����.txt" ���Ͽ� �����϶�.
	ofstream out{"�ټ�����.txt"};

	/*copy_if(strList.begin(), strList.end(), ostream_iterator<String>(out, "\n"), [](const String& s) {
		return s.getSize() == 5;
		});*/
	
	for (String& s : strList) {
			if (s.getSize() == 5)
			out << s << endl;
	}

	//save("main.cpp");
}