//-------------------------------------------------------
// 2023 1�б� STL 5�� 23�� (12�� 2)
//-------------------------------------------------------
// unordered associative containers - �������� ���� �����̳�
// 1. �������ٴ� ���� ����
// 2. �޸� ������ ȭ�鿡 ����Ѵ�
// 3. String�� ���⿡ ���ҷ� �����������?
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
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
	for (const auto& n : us)
		cout << n << ' ';
	cout << endl << endl;
}

template <>
struct hash<String> {
	size_t operator()(const String& str) const {
		return hash<string>()(str.getString());
	}
};

int main()
{
	unordered_set<String, hash<String>> us{"C++", "STL", "Container", "Iterator", "Algorithm"};

	print(us);

	//save("main.cpp");
}