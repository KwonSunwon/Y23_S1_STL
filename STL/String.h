//-----------------------------------------------------------------------------
// String.h - �ڿ��� Ȯ���ϴ� Ŭ���� - string�� �����Ϸ��� �뵵
// 2023. 4. 3
//-----------------------------------------------------------------------------

#pragma once

class ostream;
class stirng;

class String {
	size_t len{};				// Ȯ���� �ڿ��� ����Ʈ ��
	char* p{};					// Ȯ���� �ڿ��� �ּ�
	size_t id = ++sid;			// ��ü�� ������ȣ

	static size_t sid;			// Ŭ���� ����ƽ

public:
	String();
	String(const char* str);
	~String();

	// ��������ڿ� �����Ҵ翬����
	String(const String& other);
	String& operator=(const String& other);

	// �̵������ڿ� �̵��Ҵ翬����
	String(String&& other);
	String& operator=(String&& other);

	// ������ �����ε� �Լ���
	String operator+(const String& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}
	
	// 2023. 4. 4 �߰�
	friend std::istream& operator>>(std::istream& is, String& s) {
		std::string str;
		is >> str;
		delete[] s.p;
		s.len = str.size();
		s.p = new char[s.len];
		memcpy(s.p, str.data(), s.len);
		return is;
	}

	// gettor / settor
	std::string getString() const;
	size_t getLen() const;

	// �� �� �Լ���
	void print(const char* msg) const;
};