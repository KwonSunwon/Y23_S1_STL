//-------------------------------------------------------
// 2023 1�б� STL 4�� 3�� (5�� 1)
//-------------------------------------------------------
// String Ŭ���� ���� �и�
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "String.h"

int main()
{
	extern bool ����;
	���� = true;

	std::array<String, 3> a{ "345", "12", "67890" };

	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
			  });

	for (const String& s : a)
		std::cout << s << std::endl;

	save("main.cpp");
}
