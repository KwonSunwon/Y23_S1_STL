#include <iostream>
#include <algorithm>
#include <list>
#include "String.h"

using namespace std;

int main()
{
	list<String> strlist{ "123", "234", "456" };

	auto iter = find(strlist.begin(), strlist.end(), "234");
	if (iter != strlist.end())
		cout << "ã�Ҵ�" << endl;
	else
		cout << "��ã�Ҵ�" << endl;
}
