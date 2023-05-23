//-------------------------------------------------------
// 2023 1학기 STL 5월 23일 (12주 2)
//-------------------------------------------------------
// unordered associative containers - 순서없는 연관 컨테이너
// 1. 순서없다는 것을 관찰
// 2. 메모리 구조를 화면에 출력한다
// 3. String을 여기에 원소로 집어넣으려면?
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <unordered_set>
#include "save.h"
#include "String.h"

using namespace std;

void print(const auto& us)
{
	for (int i = 0; i < us.bucket_count(); ++i) {
		cout << "[" << i << "]";
		for (auto p = us.begin(i); p != us.end(i); ++p)
			cout << " - " << *p;
		cout << endl;
	}
	cout << "-----------------------------------------------------" << endl;
	for (int n : us)
		cout << n << ' ';
	cout << endl << endl;
}

int main()
{
	unordered_multiset<int> us = { 1, 2, 3, 4, 1, 1, 1 };

	print(us);

	for (int i = 0; i < 60; ++i)
		us.insert(i);

	print(us);

	//save("main.cpp");
}