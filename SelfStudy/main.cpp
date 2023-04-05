#include <iostream>
#include <array>
#include <algorithm>
#include <format>

bool observe{ false };

class String {
	size_t len{};
	std::unique_ptr<char> p{};

	size_t id = ++sid;

	static size_t sid;

public:
	String() {
		print("default constructor");
	}
	String(const char* s) : len{ strlen(s) } {
		p = std::make_unique<char>(len);
		memcpy(p.get(), s, len);

		print("constructor(char*)");
	}
	~String() {
		print("destructor");
	}
	String(const String& other) : len{ other.len } {
		p = std::make_unique<char>(len);
		memcpy(p.get(), other.p.get(), len);

		print("copy constructor");
	}

	String& operator=(const String& other) {
		if (this == &other)
			return *this;
		
		p.reset();

		len = other.len;
		p = std::make_unique<char>(len);
		memcpy(p.get(), other.p.get(), len);
		
		print("copy assignment");
		return *this;
	}

	String operator+(const String& rhs) const {
		String temp;
		temp.len = len + rhs.len;
		temp.p = std::make_unique<char>(temp.len);
		memcpy(temp.p.get(), p.get(), len);
		memcpy(temp.p.get() + len, rhs.p.get(), rhs.len);
		return temp;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (int i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}

	std::string getString() const {
		return std::string(p.get(), len);
	}

	void print(const char* msg) const {
		if (observe) {
			std::cout << std::format("[{}] - {:<20} length: {:<2d} address: ", id, msg, len);
			std::cout << static_cast<const void*>(p.get()) << '\n'; // it c++ style cast - c-style cast is (void*)p.get()
		}
	}
};

size_t String::sid{ 0 };

int main()
{
	observe = true;
	std::array<String, 3> news{ "aaa", "ccc", "bbb"};

	std::sort(news.begin(), news.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});

	for (String& s : news)
		std::cout << s << '\n';
}
