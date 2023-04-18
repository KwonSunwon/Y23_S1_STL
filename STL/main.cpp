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
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

extern bool ����;

int main()
{
	ifstream in{ "����Ʈ.txt" };
	list<String> strList{ istream_iterator<String>{in}, {} };

	// [����] ����Ʈ�� ������������ �����Ͻÿ�.

	/*sort(strList.begin(), strList.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});*/
	
	strList.sort([](const String& a, const String& b){
		return a.getString() < b.getString();
		});

	strList.unique();

	// �ܾ� ���� ������
	/*strList.sort([](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});*/

	for (String& s : strList)
		cout << s << endl;

	//save("main.cpp");
}