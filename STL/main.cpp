//-------------------------------------------------------
// 2023 1�б� STL 5�� 23�� (12�� 2)
//-------------------------------------------------------
// �����̳� ã�� �Ƿ� ����. int�� 1õ����, ã�� int�� 1����
// vector
// set
// unordered_set
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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

	{	// vector ã�� �Ƿ� ����
		vector<int> v{numbers.begin(), numbers.end()};

		cout << "���Ϳ��� ã�� ��...";
		int cnt{ 0 };

		// �ð���� ����
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (find(v.begin(), v.end(), num) != v.end())
				++cnt;
		// �ð���� ��
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "�ɸ� �ð� - " << elapsedTime << "us" << endl;
		cout << "ã�� ���� - " << cnt << endl;
	}
	cout << endl;

	{	// set ã�� �Ƿ� ����
		cout << "�� ����� ��..." << endl;
		set<int> s{numbers.begin(), numbers.end()};

		cout << "�¿��� ã�� ��...";
		int cnt{ 0 };

		// �ð���� ����
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (s.contains(num))
				cnt++;
		// �ð���� ��
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "�ɸ� �ð� - " << elapsedTime << "us" << endl;
		cout << "ã�� ���� - " << cnt << endl;
	}
	cout << endl;

	{	// unordered_set ã�� �Ƿ� ����
		cout << "�������� ����� ��..." << endl;
		unordered_set<int> us{numbers.begin(), numbers.end()};

		cout << "�������¿��� ã�� ��...";
		int cnt{ 0 };

		// �ð���� ����
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (us.contains(num))
				cnt++;
		// �ð���� ��
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "�ɸ� �ð� - " << elapsedTime << "us" << endl;
		cout << "ã�� ���� - " << cnt << endl;
	}
	cout << endl;
	
	{	// ������ vector ã�� �Ƿ� ����
		vector<int> v{numbers.begin(), numbers.end()};
		cout << "���� �����ϴ� ��..." << endl;
		sort(v.begin(), v.end());

		cout << "������ ���Ϳ��� ã�� ��...";
		int cnt{ 0 };

		// �ð���� ����
		auto start = chrono::steady_clock::now();
		for (int num : toFind)
			if (binary_search(v.begin(), v.end(), num))
				++cnt;
		// �ð���� ��
		auto end = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << endl;
		cout << "�ɸ� �ð� - " << elapsedTime << "us" << endl;
		cout << "ã�� ���� - " << cnt << endl;
	}
	cout << endl;

	//save("main.cpp");
}