//-----------------------------------------------------------------------------
// String.h - 자원을 확보하는 클래스 - string을 이해하려는 용도
// 2023. 4. 3
//-----------------------------------------------------------------------------

#pragma once

class ostream;
class stirng;

// 2023. 5. 8 추가
// String이 제공하는 반복자
class String_iterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = long long;
	using pointer = char*;
	using reference = char&;

private:
	char* p;

public:
	String_iterator() = default;
	String_iterator(char* p) : p{ p } {}

	char& operator*() const {
		return *p;
	}
	String_iterator& operator++() {
		++p;
		return *this;
	}
	
	// 2023. 5. 9 추가
	// sort에 필요한 연산자들
	difference_type operator-(const String_iterator& rhs) const {
		return p - rhs.p;
	}
	String_iterator& operator--() {
		--p;
		return *this;
	}

	String_iterator operator+(difference_type n) const {
		return String_iterator(p + n);
	}
	String_iterator operator-(difference_type n) const {
		return String_iterator(p - n);
	}

	// == != < <= > >= Relational operators
	// C++20에서는 <=>(Spaceship, Three-way comparison operator) 연산자로 한 번만 코딩
	auto operator<=>(const String_iterator& rhs) const = default;
};

// 2023. 5. 8 추가
// String이 제공하는 역방향 반복자
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
	size_t len{};				// 확보한 자원의 바이트 수
	char* p{};					// 확보한 자원의 주소
	size_t id = ++sid;			// 객체의 고유번호

	static size_t sid;			// 클래스 스태틱

public:
	String();
	String(const char* str);
	~String();

	// 복사생성자와 복사할당연산자
	String(const String& other);
	String& operator=(const String& other);

	// 이동생성자와 이동할당연산자
	// 2023. 4. 11. noexcept 추가
	String(String&& other) noexcept; // noexcept: 예외가 발생하지 않는다는 것을 컴파일러에게 알려주는 키워드
	String& operator=(String&& other) noexcept;

	// 연산자 오버로딩 함수들
	String operator+(const String& rhs) const;

	// 2023. 4. 17 추가
	bool operator==(const String& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

	// 2023. 4. 4 추가
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
		
	// 그 외 함수들
	void print(const char* msg) const;

	// 2023. 5. 8 추가
	// String이 STL 컨테이너라면 제공해야 할 멤버
	//char* begin();
	//char* end();
	String_iterator begin();
	String_iterator end();
	//std::reverse_iterator<char*> rbegin();
	//std::reverse_iterator<char*> rend();
	String_reverse_iterator rbegin();
	String_reverse_iterator rend();
};