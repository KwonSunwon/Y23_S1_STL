#pragma once

class String {
	size_t len{};
	std::unique_ptr<char[]> p{};
	// std::unique_ptr<char> 를 하게 되면 스마트 포인터가 하나의 char에 대한 메모리를 관리하게 된다.
	// 때문에 문자열 전체를 스마트 포인터가 관리하게 하기 위해서는 unique_ptr<char[]>를 사용해야 한다.

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