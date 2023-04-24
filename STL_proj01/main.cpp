#include <iostream>
#include <array>
#include <fstream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <map>
#include "Player.h"

#define DATA_COUNT 2'000'000

using namespace std;

void copy_players(); // players �迭�� ���� �迭�� ���� ����
void pointing_players();
void sort_players(); // ���� �迭�� ����
void find_player(int id);

array<Player, DATA_COUNT> players;

array<Player, DATA_COUNT> sortedByIDPlayers;
array<Player, DATA_COUNT> sortedByNamePlayers;
array<Player, DATA_COUNT> sortedByScorePlayers;

array<Player*, DATA_COUNT> sortedByIDPlayersPtr;
array<Player*, DATA_COUNT> sortedByNamePlayersPtr;
array<Player*, DATA_COUNT> sortedByScorePlayersPtr;

vector<Player> findPlayers;
int over10A{ 0 };

map<int, vector<Player*>> idMap;
//map<int, int> idMap;

int sameId{ 0 };

int main()
{
	ifstream ifs("2023 STL ���� ����", std::ios::binary);

	if (!ifs) {
		cerr << "������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	//int maxScore{ numeric_limits<int>::min() };
	//Player* maxPlayer{ nullptr };
	for (int i = 0; i < DATA_COUNT; ++i) {
		ifs >> players[i];
		//int tempScore{ players[i].getScore() };
		//if (maxScore < tempScore) {
			//maxScore = tempScore;
			//maxPlayer = &players[i];
		//}
		//players[i].sortP();
		//over10A += players[i].isOver10A();

		idMap[players[i].getId()].emplace_back(&players[i]);
		/*if (idMap.find(players[i].getId()) == idMap.end())
			idMap[players[i].getId()] = 1;
		else
			idMap[players[i].getId()]++;*/
	}

	ifs.close();

	std::cout << "1. ������ Player" << endl
		<< players[DATA_COUNT - 1] << endl
		<< "����ȱ���:" << players[DATA_COUNT - 1].getP() << endl << endl;;

	//start = chrono::high_resolution_clock::now();
	pointing_players();
	//end = chrono::high_resolution_clock::now();
	//cout << "������ �ð�: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

	// ���ĵ� �������� ������ �ð��� �ɸ�
	// �ð��� �� ���� �� �ִ� ���?
	sort_players();

	/*cout << "ID ����" << endl;
	for (const Player* p : sortedByIDPlayersPtr
		| views::take(3))
		cout << *p << endl;
	for (const Player* p : sortedByIDPlayersPtr
		| views::drop(DATA_COUNT - 3))
		cout << *p << endl;
	cout << endl;

	cout << "�̸� ����" << endl;
	for (const Player* p : sortedByNamePlayersPtr
		| views::take(3))
		cout << *p << endl;
	for (const Player* p : sortedByNamePlayersPtr
		| views::drop(DATA_COUNT - 3))
		cout << *p << endl;
	cout << endl;

	cout << "���� ����" << endl;
	for (const Player* p : sortedByScorePlayersPtr
		| views::take(3))
		cout << *p << endl;
	for (const Player* p : sortedByScorePlayersPtr
		| views::drop(DATA_COUNT - 3))
		cout << *p << endl;
	cout << endl;*/

	long long sum{ accumulate(players.begin(), players.end(), 0, [](long long total, const Player& p) {
			return total + p.getScore();
			}) };

	std::cout << "2. Score�� ���� ū Player" << endl
		<< *sortedByScorePlayersPtr[DATA_COUNT - 1] << endl
		<< "Player Socore ���: " << static_cast<double>(sum) / DATA_COUNT << endl << endl;

	int sameIdCnt{ 0 };
	ofstream sameIdFile{ "�������̵�.txt" };
	for (auto iter : idMap) {
		if (iter.second.size() >= 2) {
			sameIdCnt += iter.second.size();
			sameId = iter.second[0]->getId();
			sameIdFile << iter.second[0]->getId() << " ";
			for (auto p : iter.second) {
				sameIdFile << p->getName() << " ";
			}
		}
		/*if (iter.second >= 2)
			sameIdCnt += iter.second;*/
	}
	sameIdFile.close();

	// ���� ������ �κп� ����� ��µ��� �ʴ� �κ��� ����
	// 2345342 dwzgleeai 
	// �̷������� ����
	// �ߴ��� �ְ� Ȯ���� ���� ���� ����� �Է��� �Ǵ°� ������
	// �ڷᰡ �ʹ� Ŀ�� �׷� ���� �ֳ�?
	// �ƴϸ� ���Ͽ� ���� ������ �߸��Ǿ��� ���� ����
	// -> charGPT ���� ����ϱ� ������ ������ ������ �ʾ�
	// ���ۿ� �Ϻ� �����Ͱ� ���� ����� ����� �ȵ� �� �ִٰ� �ߴµ�
	// ��¥ ���� ���� ���� �������� ��� �۾��� ������ ������� �ϴϱ�
	// ���������� �۵���;;
	
	// 1149459
	cout << "3. ID�� ���� ���� ��ü�� ����: " << sameIdCnt << endl << endl;

	// �� �κ� �ð� ���� �� �ִ� ��� ������?
	for (Player& p : players) {
		p.sortP();
		over10A += p.isOver10A();
	}

	std::cout << "4. 'a'�� 10���� �̻��� Player ����: " << over10A << endl << endl;


	//auto iterName = find_if(sortedByNamePlayersPtr.begin(), sortedByNamePlayersPtr.end(), [](const Player* p, const Player* ptr) {
		//return p == ptr;
		//});
	// ��...
	// �����غ��ϱ� �ּҰ��� ������ ã�´ٰ� �ص� �ּ� ���� ���ĵȰ� �ƴϴϱ� �ᱹ ���� Ž���� �ؾ��ϴµ�
	// �׷��ٸ� �ּҰ��� �̿��ؼ� ã�°ͺ��� ID ���� �迭���� ã�Ƴ� ��ü�� �̿��ؼ� ��ü ������ Ȯ���ϰ�
	// �װ� �̿��ؼ� ���� ���� Ž���� �ϴ°� �� ������ ����

	// + 5�� ���� �ñ��� �߰�
	// ���࿡ ���� id�� ��ü�� �� �� �̻� ������ ��
	// �ش� ��ü�� �̸� ���Ŀ����� id�� �ش��ϴ� ��� ��ü�� ���ؼ� �ش� ���� �ؾ� �ϴ°ǰ�?

	for (const auto& p : sortedByIDPlayersPtr
		| views::drop(DATA_COUNT - 5)) {
		cout << *p << endl;
	}


	findPlayers.reserve(10);
	int id;
	do {
		cout << "ID�� �Է��ϼ���: ";
		cin >> id;
		find_player(id);
	} while (true);
}

// ���� �����غ��ϱ� ���� ���縦 �ϴ°� �ƴ϶�
// �����ͷ� ����Ű�⸸ �ϸ� �ŰܾߵǴ� ������ ���� �پ��ϱ�
// �� ������ �Ƴ�?
// �ӵ� ���� ��û��;;
void copy_players()
{
	//auto start = chrono::high_resolution_clock::now();
	//copy(players.begin(), players.end(), sortedByIDPlayers.begin());
	//copy(players.begin(), players.end(), sortedByNamePlayers.begin());
	//copy(players.begin(), players.end(), sortedByScorePlayers.begin());
	//auto end = chrono::high_resolution_clock::now();
	//auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	//cout << duration.count() << "us" << endl;

	sortedByIDPlayers = players;
	sortedByNamePlayers = players;
	sortedByScorePlayers = players;
}

void pointing_players()
{
	for (int i = 0; i < DATA_COUNT; ++i) {
		sortedByIDPlayersPtr[i] = &players[i];
		sortedByNamePlayersPtr[i] = &players[i];
		sortedByScorePlayersPtr[i] = &players[i];
	}
}

void sort_players()
{
	//ranges::sort(sortedByIDPlayers, [](const Player& a, const Player& b) {
	//	return a.getId() < b.getId();
	//	});
	//ranges::sort(sortedByNamePlayers, [](const Player& a, const Player& b) {
	//	return a.getName() < b.getName();
	//	});
	//ranges::sort(sortedByScorePlayers, [](const Player& a, const Player& b) {
	//	return a.getScore() < b.getScore();
	//	});

	ranges::sort(sortedByIDPlayersPtr, [](const Player* a, const Player* b) {
		return a->getId() < b->getId();
		});
	ranges::sort(sortedByNamePlayersPtr, [](const Player* a, const Player* b) {
		return a->getName() < b->getName();
		});
	ranges::sort(sortedByScorePlayersPtr, [](const Player* a, const Player* b) {
		return a->getScore() < b->getScore();
		});
}

void find_player(int playerId)
{
	findPlayers.clear();

	auto iter = lower_bound(sortedByIDPlayersPtr.begin(), sortedByIDPlayersPtr.end(), playerId, [](const Player* p, int id) {
		return p->getId() < id;
		});

	if (iter == sortedByIDPlayersPtr.end() || (*iter)->getId() != playerId) {
		cout << "ID�� " << playerId << "�� Player�� �����ϴ�." << endl << endl;
		return;
	}

	//=====================================================
	// ID ���� �迭���� �ش� ID�� ��ü�� �յ� ��ü ���
	// ���� ID�� �����ϴ� ��� vector�� ��� ����
	cout << "ID ���� ����" << endl;
	if (iter != sortedByIDPlayersPtr.begin())
		cout << **(iter - 1) << endl;
	while ((*iter)->getId() == playerId && iter != sortedByIDPlayersPtr.end()) {
		findPlayers.emplace_back((*iter)->getName(), (*iter)->getScore(), (*iter)->getId(), (*iter)->getNum(), (*iter)->getP());
		cout << **iter++ << endl;
	}
	if (iter != sortedByIDPlayersPtr.end())
		cout << **iter << endl << endl;
	//=====================================================


	//=====================================================
	// �̸� ���� �迭���� �ش� ID�� ��ü�� �յ� ��ü ���
	cout << "�̸� ���� ����" << endl;
	for (const Player& p : findPlayers) {
		string target = p.getName();
		auto iterName = lower_bound(sortedByNamePlayersPtr.begin(), sortedByNamePlayersPtr.end(), target, [](const Player* p, const string& name) {
			return p->getName() < name;
			});
		if (iterName != sortedByNamePlayersPtr.begin())
			cout << **(iterName - 1) << endl;
		cout << **iterName << endl;
		if (iterName != sortedByNamePlayersPtr.end() - 1)
			cout << **(iterName + 1) << endl;
		cout << endl;
	}
	cout << endl;
	//=====================================================

	//=====================================================
	// ���� ���� �迭���� �ش� ID�� ��ü�� �յ� ��ü ���
	cout << "���� ���� ����" << endl;
	for (const Player& p : findPlayers) {
		int target = p.getScore();
		auto iterScore = lower_bound(sortedByScorePlayersPtr.begin(), sortedByScorePlayersPtr.end(), target, [](const Player* p, int score) {
			return p->getScore() < score;
			});
		if (iterScore != sortedByScorePlayersPtr.begin())
			cout << **(iterScore - 1) << endl;
		cout << **iterScore << endl;
		if (iterScore != sortedByScorePlayersPtr.end() - 1)
			cout << **(iterScore + 1) << endl;
		cout << endl;
	}
	cout << endl;
	//=====================================================
}