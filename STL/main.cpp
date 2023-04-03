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
#include <string>
#include "save.h"

// [����] String�� �ڵ��϶�
// ��� special �Լ��� ���� �޽����� �߰��϶�
// ������ ��ü�� ������ȣ�� �ο��϶�

bool ����{ false };

class String {
	size_t len{};
	char* p{};		// [����] unique_ptr<char> p �� �ٲ㼭 �ڵ��� �� ��

	size_t id = ++sid; // ��ü�� ������ȣ

	static size_t sid;

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
	String()
	{
		print("����Ʈ ����");
	}
	String(const char* str) : len{ strlen(str) }
	{
		p = new char[len];
		memcpy(p, str, len);	// DMA: Direct Memory Access - CPU ���پ��� �ٷ� �޸𸮿� ����

		print("����(char*)");
	}
	~String()
	{
		print("�Ҹ���");
		delete[] p;
	}

	// ���� ����
	/*String(const String& s) : len{ s.len }
	{
		p = new char[len];
		memcpy(p, s.p, len);

		print("�������");
	}*/
	String(const String& other) : len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);

		print("�������");
	}
	// ��������ڸ� �ڵ��ߴٸ� �����Ҵ翬���ڵ� �ݵ�� �ڵ��ؾ���
	String& operator=(const String& other)
	{
		if (this == &other)
			return *this;

		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);

		print("�����Ҵ翬����");
		return *this;
	}

	/*String operator+(const String& other) // �Լ��� const �ٿ���� �Ѵ�.
	{
		String temp;
		temp.len = this->len + other.len;
		temp.p = new char[temp.len];
		memcpy(temp.p, this->p, this->len);
		memcpy(temp.p + this->len, other.p, other.len);
		return temp;
	}*/
	String operator+(const String& rhs) const
	{
		String temp; // ������ ����ٸ� default �����ڰ� ���� ���� String() = default �߰�
		temp.len = len + rhs.len;
		temp.p = new char[temp.len];
		memcpy(temp.p, p, len);
		memcpy(temp.p + len, rhs.p, rhs.len);
		return temp;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

	std::string getString() const
	{
		return std::string(p, len);
	}

	void print(const char* msg) const
	{
		if (����) {
			std::cout << "[" << id << "] - " << msg << ", ����: " << len
				<< ", �ּ�: " << (void*)p << '\n';
		}
	}
};

size_t String::sid{ 0 };

int main()
{
	���� = true;
	// [����] ��ü�� 3���� �� �޸𸮿� � ���� �Ͼ���� Ȯ���غ���
	std::array<String, 3> news{ "������", "����", "����"};

	// [����] news�� �������� �����϶�
	std::sort(news.begin(), news.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});


	for (String& s : news)
		std::cout << s << '\n';

	//save("main.cpp");
}
