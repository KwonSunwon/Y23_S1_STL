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

class String
{
	size_t len{};				// Ȯ���� �ڿ��� ����Ʈ ��
	char* p{};					// Ȯ���� �ڿ��� �ּ�
	size_t id = ++sid;			// ��ü�� ������ȣ

	static size_t sid;			// Ŭ���� ����ƽ

public:
	String()
	{
		print("����Ʈ ������");
	}
	String(const char* str) : len{ strlen(str) }
	{
		p = new char[len];
		memcpy(p, str, len);

		print("������(char*)");
	}
	~String()
	{
		print("�Ҹ���");
		delete[] p;
	}

	// ��������ڿ� �����Ҵ翬����
	String(const String& other) : len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);

		print("�������");
	}
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

	// �̵������ڿ� �̵��Ҵ翬����
	String(String&& other) // && - r-value referens
	{
		len = other.len;
		p = other.p;

		// other�� �����Ѵ�. -> dangling ptr ����
		other.len = 0;
		other.p = nullptr;

		print("�̵�������");
	}

	String& operator=(String&& other)
	{
		if (this == &other)
			return *this;

		// ���� Ȯ���� �ڿ� ����
		delete[] p;

		// other �ڿ��� �����´�
		len = other.len;
		p = other.p;

		// other�� �ʱ�ȭ�Ѵ�
		other.len = 0;
		other.p = nullptr;

		print("�̵��Ҵ翬����");

		return *this;
	}

	String operator+(const String& rhs) const
	{
		String temp;
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

	// gettor / settor
	std::string getString() const
	{
		return std::string(p, len);
	}

	// �� �� �Լ���
	void print(const char* msg) const
	{
		if (����)
		{
			std::cout << "[" << id << "] - " << msg << ", ����: " << len
				<< ", �ּ�: " << (void*)p << '\n';
		}
	}
};

size_t String::sid{ 0 };

int main()
{
	���� = true;
	String a{ "12345" };
	String b{ "4567890" };
	b = std::move(a);

	std::cout << a << '\n';
	std::cout << b << '\n';

	save("main.cpp");
}
