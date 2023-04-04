//-----------------------------------------------------------------------------
// String.cpp - �ڿ��� Ȯ���ϴ� Ŭ����
// 2023. 4. 3
//-----------------------------------------------------------------------------

#include <string>
#include <iostream>
#include "String.h"

bool ����{ false };				// �����ϰ� ������ true�� ����

String::String()
{
	print("����Ʈ ������");
}

String::String(const char* str) : len{ strlen(str) }
{
	p = new char[len];
	memcpy(p, str, len);

	print("������(char*)");
}

String::~String()
{
	print("�Ҹ���");
	delete[] p;
}

// ��������ڿ� �����Ҵ翬����
String::String(const String& other) : len{ other.len }
{
	p = new char[len];
	memcpy(p, other.p, len);

	print("�������");
}

String& String::operator=(const String& other)
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
String::String(String&& other) // && - r-value referens
{
	len = other.len;
	p = other.p;

	// other�� �����Ѵ�. -> dangling ptr ����
	other.len = 0;
	other.p = nullptr;

	print("�̵�������");
}

String& String::operator=(String&& other)
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

// ������ �����ε� �Լ���
String String::operator+(const String& rhs) const
{
	String temp;
	temp.len = len + rhs.len;
	temp.p = new char[temp.len];
	memcpy(temp.p, p, len);
	memcpy(temp.p + len, rhs.p, rhs.len);
	return temp;
}

// gettor / settor
std::string String::getString() const
{
	return std::string(p, len);
}

// 2023. 4. 4 �߰�
size_t String::getSize() const
{
	return len;
}

// �� �� �Լ���
void String::print(const char* msg) const
{
	if (����) {
		std::cout << "[" << id << "] - " << msg << ", ����: " << len
			<< ", �ּ�: " << (void*)p << std::endl;
	}
}

size_t String::sid{ 0 };