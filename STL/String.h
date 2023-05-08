//-----------------------------------------------------------------------------
// String.h - �ڿ��� Ȯ���ϴ� Ŭ���� - string�� �����Ϸ��� �뵵
// 2023. 4. 3
//-----------------------------------------------------------------------------

#pragma once

class ostream;
class stirng;

// 2023. 5. 8 �߰�
// String�� �����ϴ� ������ �ݺ���
class String_reverse_iterator {
	char* p;
public:
	String_reverse_iterator() = default;
	String_reverse_iterator(char* p) : p{ p } {}

	char& operator*() const {
		return *(p - 1);
	}
	String_reverse_iterator& operator++() {
		--p;
		return *this;
	}
	bool operator!=(const String_reverse_iterator& rhs) const {
		return p != rhs.p;
	}
};

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
	// 2023. 4. 11. noexcept �߰�
	String(String&& other) noexcept; // noexcept: ���ܰ� �߻����� �ʴ´ٴ� ���� �����Ϸ����� �˷��ִ� Ű����
	String& operator=(String&& other) noexcept;

	// ������ �����ε� �Լ���
	String operator+(const String& rhs) const;

	// 2023. 4. 17 �߰�
	bool operator==(const String& rhs) const;

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
	size_t getSize() const;

	// �� �� �Լ���
	void print(const char* msg) const;

	// 2023. 5. 8 �߰�
	// String�� STL �����̳ʶ�� �����ؾ� �� ���
	char* begin();
	char* end();
	//std::reverse_iterator<char*> rbegin();
	//std::reverse_iterator<char*> rend();
	String_reverse_iterator rbegin();
	String_reverse_iterator rend();
};