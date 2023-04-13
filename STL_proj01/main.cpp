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

void copyPlayers(); // players 배열을 정렬 배열에 각각 복사
void pointingPlayers();
void sortPlayers(); // 정렬 배열을 정렬

array<Player, DATA_COUNT> players;

array<Player, DATA_COUNT> sortedByIDPlayers;
array<Player, DATA_COUNT> sortedByNamePlayers;
array<Player, DATA_COUNT> sortedByScorePlayers;

array<Player*, DATA_COUNT> sortedByIDPlayersPtr;
array<Player*, DATA_COUNT> sortedByNamePlayersPtr;
array<Player*, DATA_COUNT> sortedByScorePlayersPtr;

int main()
{
	ifstream ifs("2023 STL 과제 파일", std::ios::binary);

	if (!ifs) {
		cerr << "파일을 열 수 없습니다." << endl;
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
	std::cout << "1. 마지막 Player" << endl
		<< players[DATA_COUNT - 1] << endl << endl;

	long long sum{ accumulate(players.begin(), players.end(), 0, [](long long total, const Player& p) {
			return total + p.getScore();
			}) };

	auto start = chrono::high_resolution_clock::now();
	//copyPlayers();
	auto end = chrono::high_resolution_clock::now();
	cout << "복사 시간: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

	start = chrono::high_resolution_clock::now();
	pointingPlayers();
	end = chrono::high_resolution_clock::now();
	cout << "포인팅 시간: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

	sortPlayers();

	for (const Player* p : sortedByIDPlayersPtr
		| views::take(10))
		cout << *p << endl;
	for (const Player* p : sortedByIDPlayersPtr
		| views::drop(DATA_COUNT - 10))
		cout << *p << endl;

	//std::cout << "2. Score가 가장 큰 Player" << endl
		//<< sortedByScorePlayers[DATA_COUNT - 1] << endl
		//<< "Player Socore 평균: " << static_cast<double>(sum) / DATA_COUNT << endl << endl;

	auto iter = lower_bound(sortedByIDPlayersPtr.begin(), sortedByIDPlayersPtr.end(), 4, [](const Player* p, int id) {
		return p->getId() < id;
		});

	cout << endl;
	cout << *iter << endl;
	cout << **iter << endl;
	cout << endl;

	if (iter != sortedByIDPlayersPtr.end() && (*iter)->getId() == 4) {
		cout << "ID가 4인 Player: " << **iter << endl;
	}
	else {
		cout << "ID가 4인 Player가 없습니다." << endl;
	}
	cout << endl;

	auto iterName = find_if(sortedByNamePlayersPtr.begin(), sortedByNamePlayersPtr.end(), [](const Player* p, const Player* ptr) {
		return p == ptr;
		});
	// 흠...
	// 생각해보니까 주소값을 가지고 찾는다고 해도 주소 값이 정렬된게 아니니까 결국 선형 탐색을 해야하는데
	// 그렇다면 주소값을 이용해서 찾는것보다 ID 정렬 배열에서 찾아낸 객체를 이용해서 객체 내용을 확인하고
	// 그걸 이용해서 각각 이진 탐색을 하는게 더 빠를거 같음

	// + 5번 과제 궁금증 추가
	// 만약에 같은 id를 객체가 두 개 이상 존재할 때
	// 해당 객체의 이름 정렬에서도 id에 해당하는 모든 객체에 대해서 해당 일을 해야 하는건가?

	if (iterName != sortedByNamePlayersPtr.end() && *iterName == *iter) {
		cout << "ID가 4인 Player: " << **iterName << endl;
	}
	else {
		cout << "ID가 4인 Player가 없습니다." << endl;
	}
}

// 복사 생각해보니까 깊은 복사를 하는게 아니라
// 포인터로 가리키기만 하면 옮겨야되는 데이터 수가 줄어드니까
// 더 빠른거 아냐?
// 속도 차이 엄청남;;
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

