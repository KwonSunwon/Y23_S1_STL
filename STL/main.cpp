//-------------------------------------------------------
// 2023 1학기 STL 5월 23일 (12주 2)
//-------------------------------------------------------
// 컨테이너 찾기 실력 검증. int값 1천만개, 찾을 int값 1만개
// vector
// set
// unordered_set
//-------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - latest, SDL/아니오
//-------------------------------------------------------

#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>
#include "save.h"
#include "String.h"

using namespace std;

const int NUM = 10'000'000;
const int FNUM = 10'000;

array<int, NUM> numbers;
array<int, FNUM> toFind;

default_random_engine dre;
uniform_int_distribution uid{ 1, 100'000'000 };

int main()
{
	for (int& num : numbers)
		num = uid(dre);
	for (int& num : toFind)
		num = uid(dre);

	{	// vector 찾기 실력 검증
		vector<int> v{numbers.begin(), numbers.end()};

		cout << "벡터에서 찾는 중...";
		int cnt{ 0 };

		// 시간재기 시작
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (find(v.begin(), v.end(), num) != v.end())
				++cnt;
		// 시간재기 끝
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "걸린 시간 - " << elapsedTime << "us" << endl;
		cout << "찾은 개수 - " << cnt << endl;
	}
	cout << endl;

	{	// set 찾기 실력 검증
		cout << "셋 만드는 중..." << endl;
		set<int> s{numbers.begin(), numbers.end()};

		cout << "셋에서 찾는 중...";
		int cnt{ 0 };

		// 시간재기 시작
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (s.contains(num))
				cnt++;
		// 시간재기 끝
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "걸린 시간 - " << elapsedTime << "us" << endl;
		cout << "찾은 개수 - " << cnt << endl;
	}
	cout << endl;

	{	// unordered_set 찾기 실력 검증
		cout << "언오더드셋 만드는 중..." << endl;
		unordered_set<int> us{numbers.begin(), numbers.end()};

		cout << "언오더드셋에서 찾는 중...";
		int cnt{ 0 };

		// 시간재기 시작
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (us.contains(num))
				cnt++;
		// 시간재기 끝
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "걸린 시간 - " << elapsedTime << "us" << endl;
		cout << "찾은 개수 - " << cnt << endl;
	}
	cout << endl;
	
	{	// 정렬한 vector 찾기 실력 검증
		vector<int> v{numbers.begin(), numbers.end()};
		cout << "벡터 정렬하는 중..." << endl;
		sort(v.begin(), v.end());

		cout << "정렬한 벡터에서 찾는 중...";
		int cnt{ 0 };

		// 시간재기 시작
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (binary_search(v.begin(), v.end(), num))
				++cnt;
		// 시간재기 끝
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "걸린 시간 - " << elapsedTime << "us" << endl;
		cout << "찾은 개수 - " << cnt << endl;
	}
	cout << endl;

	//save("main.cpp");
}