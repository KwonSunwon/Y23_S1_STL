//-------------------------------------------------------
// 2023 1�б� STL 5�� 16�� (11�� 2)
//-------------------------------------------------------
// Associative �����̳� = set/map (��/���)
// "�̻��� ������ �ٸ���.txt" - 26634
// set�� String�� ��� ����...
// == set�� ���ı����� �����ϴ� ��� ==
// 1. String�� operator<�� ����
// 2. less<String>�� specialization
// 3. ȣ�Ⱑ��Ÿ���� ����
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <set>
#include <algorithm>
#include <ranges>
#include <random>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// 1���� 100���� ������ �ϳ��� �������� �����ϰ� ����϶�.
	vector<int> v;
	//set<int> s;
	
	default_random_engine dre{ random_device()() };
	//uniform_int_distribution<int> uid(1, 45);

	v.resize(45);
	iota(v.begin(), v.end(), 1);


	for (int i = 0; i < 100; ++i) {
		shuffle(v.begin(), v.end(), dre);
		for (int i = 0; i < 6; ++i)
			cout << v[i] << " ";
		cout << endl;
	}

	//while (s.size() != 100){
	//	int n = uid(dre);
	//	if (s.insert(n).second)
	//		cout << n << " ";
	//}

	//save("main.cpp");
}