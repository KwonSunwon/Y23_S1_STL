//-------------------------------------------------------
// 2023 1�б� STL 5�� 22�� (12�� 1)
//-------------------------------------------------------
// map
//-------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - latest, SDL/�ƴϿ�
//-------------------------------------------------------

#include <iostream>
#include <map>
#include <list>
#include <utility>
#include "save.h"
#include "String.h"

using namespace std;

int main()
{
	// ����ȸ��, ����۵�
	map<String, list<String>> game{
		{"�� ���", { "�����縷", "�����縷", "������" }},
		{ "��������", {"���ƿ�", "������ũ��", "��Ÿ�ʵ�", "�͹̳�����"} },
	};

	//game.insert(pair<String, list<String>> {"���̾�", { "���׿��극����", "�߷ζ�Ʈ" }});
	game.insert(make_pair("���̾�", list<String>{ "���׿��극����", "�߷ζ�Ʈ" }));

	cout << "���� ���� �� - " << game.size() << endl;

	// ���� Ű���� �����ϰ� �ʹٸ� extract ����� �̿��Ѵ�.(since C++17)
	auto handle = game.extract("�� ���");
	handle.key() = "�޾��";
	game.insert(move(handle));

	// ȸ�� �ϳ��� ������ �߰��Ѵ�.
	//game["���̾�"].push_back("�����������׶�"); // �����迭(associative array)
	//list<String>& val = game["���̾�"];
	auto& val = game["���̾�"]; // ����� �˰� ���
	val.insert(val.begin(), "��������");

	//auto it = game.find("���̾�");
	//if (it != game.end())
	//	it->second.push_back("�����������׶�");

	for (const auto& [ȸ��, ���ӵ�] : game) {
		cout << ȸ�� << " - ";
		for (const String& ���� : ���ӵ�)
			cout << "\"" << ���� << "\" ";
		cout << endl;
	}

	save("main.cpp");
}