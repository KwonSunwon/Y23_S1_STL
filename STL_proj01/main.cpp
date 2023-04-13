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

void copyPlayers(); // players �迭�� ���� �迭�� ���� ����
void pointingPlayers();
void sortPlayers(); // ���� �迭�� ����

array<Player, DATA_COUNT> players;

array<Player, DATA_COUNT> sortedByIDPlayers;
array<Player, DATA_COUNT> sortedByNamePlayers;
array<Player, DATA_COUNT> sortedByScorePlayers;

array<Player*, DATA_COUNT> sortedByIDPlayersPtr;
array<Player*, DATA_COUNT> sortedByNamePlayersPtr;
array<Player*, DATA_COUNT> sortedByScorePlayersPtr;

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
	}
	std::cout << "1. ������ Player" << endl
		<< players[DATA_COUNT - 1] << endl << endl;

	long long sum{ accumulate(players.begin(), players.end(), 0, [](long long total, const Player& p) {
			return total + p.getScore();
			}) };

	auto start = chrono::high_resolution_clock::now();
	//copyPlayers();
	auto end = chrono::high_resolution_clock::now();
	cout << "���� �ð�: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

	start = chrono::high_resolution_clock::now();
	pointingPlayers();
	end = chrono::high_resolution_clock::now();
	cout << "������ �ð�: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

	sortPlayers();

	for (const Player* p : sortedByIDPlayersPtr
		| views::take(10))
		cout << *p << endl;
	for (const Player* p : sortedByIDPlayersPtr
		| views::drop(DATA_COUNT - 10))
		cout << *p << endl;

	//std::cout << "2. Score�� ���� ū Player" << endl
		//<< sortedByScorePlayers[DATA_COUNT - 1] << endl
		//<< "Player Socore ���: " << static_cast<double>(sum) / DATA_COUNT << endl << endl;

	auto iter = lower_bound(sortedByIDPlayersPtr.begin(), sortedByIDPlayersPtr.end(), 4, [](const Player* p, int id) {
		return p->getId() < id;
		});

	cout << endl;
	cout << *iter << endl;
	cout << **iter << endl;
	cout << endl;

	if (iter != sortedByIDPlayersPtr.end() && (*iter)->getId() == 4) {
		cout << "ID�� 4�� Player: " << **iter << endl;
	}
	else {
		cout << "ID�� 4�� Player�� �����ϴ�." << endl;
	}
	cout << endl;

	auto iterName = find_if(sortedByNamePlayersPtr.begin(), sortedByNamePlayersPtr.end(), [](const Player* p, const Player* ptr) {
		return p == ptr;
		});
	// ��...
	// �����غ��ϱ� �ּҰ��� ������ ã�´ٰ� �ص� �ּ� ���� ���ĵȰ� �ƴϴϱ� �ᱹ ���� Ž���� �ؾ��ϴµ�
	// �׷��ٸ� �ּҰ��� �̿��ؼ� ã�°ͺ��� ID ���� �迭���� ã�Ƴ� ��ü�� �̿��ؼ� ��ü ������ Ȯ���ϰ�
	// �װ� �̿��ؼ� ���� ���� Ž���� �ϴ°� �� ������ ����

	// + 5�� ���� �ñ��� �߰�
	// ���࿡ ���� id�� ��ü�� �� �� �̻� ������ ��
	// �ش� ��ü�� �̸� ���Ŀ����� id�� �ش��ϴ� ��� ��ü�� ���ؼ� �ش� ���� �ؾ� �ϴ°ǰ�?

	if (iterName != sortedByNamePlayersPtr.end() && *iterName == *iter) {
		cout << "ID�� 4�� Player: " << **iterName << endl;
	}
	else {
		cout << "ID�� 4�� Player�� �����ϴ�." << endl;
	}
}

// ���� �����غ��ϱ� ���� ���縦 �ϴ°� �ƴ϶�
// �����ͷ� ����Ű�⸸ �ϸ� �ŰܾߵǴ� ������ ���� �پ��ϱ�
// �� ������ �Ƴ�?
// �ӵ� ���� ��û��;;
void copyPlayers() 
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

void pointingPlayers()
{
	for (int i = 0; i < DATA_COUNT; ++i) {
		sortedByIDPlayersPtr[i] = &players[i];
		sortedByNamePlayersPtr[i] = &players[i];
		sortedByScorePlayersPtr[i] = &players[i];
	}
}

void sortPlayers()
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

