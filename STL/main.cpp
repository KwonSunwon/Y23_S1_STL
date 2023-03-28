//-------------------------------------------------------
// 2023 1�б� STL 3�� 28�� (4�� 2)
//-------------------------------------------------------
// C++ Ŭ���� ���� - String Ŭ������ �����.
// ������ String Ŭ������ STL �����̳ʷ� ������Ų��.
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"

class String {
	size_t len{};
	char* p{};		// [����] unique_ptr<char> p �� �ٲ㼭 �ڵ��� �� ��

public:
	/*String(const char str[])
	{
		len = strlen(str);
		p = new char[len + 1];
		strcpy(p, str);
	}
	
	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		return os << s.p; // ���� �۵� �Ѵٰ� �ص� �߸��� �ڵ�, string �� ������ ���� �������� �ʴ´�
	}*/

	String(const char* str) : len{ strlen(str) }
	{
		p = new char[len];
		memcpy(p, str, len);	// DMA: Direct Memory Access - CPU ���پ��� �ٷ� �޸𸮿� ����
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

};

int main()
{
	String a{ "123" }; // ������ �������� 32����Ʈ ũ�⸦ ���� -> ���� �Ҵ��� �Ѵ�.

	std::cout << a << '\n';

	save("main.cpp");
}
