#pragma once

class String {
	size_t len{};
	std::unique_ptr<char> p{};

	size_t id = ++sid;

	static size_t sid;

public:
	String();
	String(const char* s);
	~String();
	String(const String& other);

	String& operator=(const String& other);
	String operator+(const String& rhs) const;

	String(String&& other);
	String& operator=(String&& other);

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (int i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}

	std::string getString() const;
	size_t getSize() const;

	void print(const char* msg) const;
};