//-------------------------------------------------------
// 2023 1�б� STL 5�� 9�� (10�� 2)
//-------------------------------------------------------
// String�� STL �����̳ʷ� ����� ����. - begin(), end()
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;

//template<typename Iter, typename t>
//Iter my_find(Iter b, Iter e, t v)
//{
//	while (b != e) {
//		if (*b == v)
//			return b;
//		++b;
//	}
//	return e;
//}

template<class Iter, class Val>
Iter my_find(Iter beg, Iter end, Val val)
{
	while (beg != end) {
		if (*beg == val)
			return beg;
		++beg;
	}
	return end;
}

template<class Iter, class Pred>
Iter my_find_if(Iter beg, Iter end, Pred pred)
{
	while (beg != end) {
		if (pred(*beg))
			return beg;
		++beg;
	}
	return end;
}

int main()
{
	String s{ "coNtainers - iterators - Algorithms" };

	// ó�� ������ �빮�ڴ� �� ��° ����?
	auto iter = my_find_if(s.begin(), s.end(), [](char c) {return isupper(c); });
	if (iter != s.end())
		cout << distance(s.begin(), iter) + 1 << "�� ° ��ġ���� �߰�" << endl;
	else
		cout << "����" << endl;

	/*auto iter = my_find(s.begin(), s.end(), 's');
	if (iter != s.end())
		cout << distance(s.begin(), iter) + 1 << " ��ġ���� �߰�" << endl;
	else
		cout << "����" << endl;

	list<int> li{ 1,2,3,4,5,6,7,8,9,10 };
	auto iter2 = my_find(li.begin(), li.end(), 5);
	if (iter2 != li.end())
		cout << distance(li.begin(), iter2) + 1 << " ��ġ���� �߰�" << endl;
	else
		cout << "����" << endl;*/

	//save("main.cpp");
}