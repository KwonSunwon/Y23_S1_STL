//-----------------------------------------------------------------------------
// String.h - 자원을 확보하는 클래스 - string을 이해하려는 용도
// 2023. 4. 3
//-----------------------------------------------------------------------------

#pragma once

class ostream;
class stirng;

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
	String(String&& other);
	String& operator=(String&& other);

	// 연산자 오버로딩 함수들
	String operator+(const String& rhs) const;

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
	size_t getLen() const;

	// 그 외 함수들
	void print(const char* msg) const;
};