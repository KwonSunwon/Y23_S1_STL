#pragma once

class String {
	size_t len{};
	std::unique_ptr<char[]> p{};

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

	std::string getString() const;
	size_t getSize() const;

	void print(const char* msg) const;
};