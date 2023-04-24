//-------------------------------------------------------
// 2023 1�б� STL 4�� 24�� (8�� 1)
// 4�� 25�� - (8�� 2) �߰�����
//-------------------------------------------------------
// span, mdspan
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <span>
#include <string>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

void print(span<char>);

int main()
{
	string a = "hello world";

	print(a);

	const char* p = "hello world";
	print(span<char>((char*)p, (char*)p + strlen(p)));

	//save("main.cpp");
}

void print(span<char> s)
{
	for(auto p = s.rbegin(); p != s.rend(); ++p)
		cout << *p << ' ';
	cout << endl;
}