#pragma once

class String {
	size_t len{};
	std::unique_ptr<char[]> p{};
	// std::unique_ptr<char> �� �ϰ� �Ǹ� ����Ʈ �����Ͱ� �ϳ��� char�� ���� �޸𸮸� �����ϰ� �ȴ�.
	// ������ ���ڿ� ��ü�� ����Ʈ �����Ͱ� �����ϰ� �ϱ� ���ؼ��� unique_ptr<char[]>�� ����ؾ� �Ѵ�.

	size_t id = ++sid;

	static size_t sid;

public:
	// special member function
	String();
	String(const char* s);
	~String();
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other) noexcept;
	String& operator=(String&& other) noexcept;

	// operator overoading
	String operator+(const String& rhs) const;
	bool operator==(const String& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for(int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

	friend std::istream& operator>>(std::istream& is, String& s) {
		std::string str;
		is >> str;

		s.p.reset();

		s.len = str.size();
		s.p = std::make_unique<char[]>(s.len);
		memcpy(s.p.get(), str.data(), s.len);

		return is;
	}

	// getter/setter
	std::string getString() const;
	size_t getSize() const;

	void print(const char* msg) const;
};