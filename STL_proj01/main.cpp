#include <iostream>
#include <array>
#include <fstream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <span>
#include "Player.h"

#define DATA_COUNT 2'000'000

#define DEBUG 0

using namespace std;

void pointing_players();
void sort_players(); // 정렬 배열을 정렬
void find_player(int id);

array<Player, DATA_COUNT> players;

array<Player*, DATA_COUNT> sortedByIDPlayersPtr;
array<Player*, DATA_COUNT> sortedByNamePlayersPtr;
array<Player*, DATA_COUNT> sortedByScorePlayersPtr;

int over10A{ 0 };

int main()
{
	ifstream ifs("2023 STL 과제 파일", std::ios::binary);

	if (!ifs) {
		cerr << "파일을 열 수 없습니다." << endl;
		exit(1);
	}

#if DEBUG
	auto start{ chrono::high_resolution_clock::now() };
#endif

	for (int i = 0; i < DATA_COUNT; ++i) {
		ifs >> players[i];
	}

#if DEBUG
	auto end{ chrono::high_resolution_clock::now() };
	auto duration{ chrono::duration_cast<chrono::milliseconds>(end - start) };
	cout << "읽기 시간: " << duration.count() << "ms" << endl;
#endif

	std::cout << "1. 마지막 Player" << endl
		<< players[DATA_COUNT - 1] << endl
		<< "저장된글자:" << players[DATA_COUNT - 1].getP() << endl << endl;;

#if DEBUG
	start = chrono::high_resolution_clock::now();
#endif

	pointing_players();
	sort_players();

#if DEBUG
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "정렬 시간: " << duration.count() << "ms" << endl;
#endif


#if DEBUG
	start = chrono::high_resolution_clock::now();
#endif

	long long sum = sumScore(span<Player>{players});

#if DEBUG
	end = chrono::high_resolution_clock::now();
	auto durationUs = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "총합 구하는 시간:" << durationUs.count() << "us" << endl;
#endif

	std::cout << "2. Score가 가장 큰 Player" << endl
		<< *sortedByScorePlayersPtr[DATA_COUNT - 1] << endl
		<< "Player Score 평균: " << fixed << static_cast<double>(sum) / DATA_COUNT << endl << endl;

	ofstream sameIdFile{ "같은아이디.txt" };

#if DEBUG
	start = chrono::high_resolution_clock::now();
#endif

	size_t sameIdCnt{ 0 };

	if (sortedByIDPlayersPtr[0]->getId() == sortedByIDPlayersPtr[1]->getId()) {
		sameIdCnt++;
		sameIdFile << sortedByIDPlayersPtr[0]->getId() << " "
			<< sortedByIDPlayersPtr[0]->getName() << " ";
	}
	for (int i = 1; i < DATA_COUNT - 1; ++i) {
		if (sortedByIDPlayersPtr[i]->getId() == sortedByIDPlayersPtr[i - 1]->getId()) {
			sameIdCnt++;
			sameIdFile << sortedByIDPlayersPtr[i]->getName() << " ";
		}
		else if (sortedByIDPlayersPtr[i]->getId() == sortedByIDPlayersPtr[i + 1]->getId()) {
			sameIdCnt++;
			sameIdFile << sortedByIDPlayersPtr[i]->getId() << " "
				<< sortedByIDPlayersPtr[i]->getName() << " ";
		}
	}
	if (sortedByIDPlayersPtr[DATA_COUNT - 1]->getId() == sortedByIDPlayersPtr[DATA_COUNT - 2]->getId()) {
		sameIdCnt++;
		sameIdFile << sortedByIDPlayersPtr[DATA_COUNT - 1]->getName();
	}

#if DEBUG
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "수행 시간: " << duration.count() << "ms" << endl;
#endif

	//sameIdFile << flush;
	sameIdFile.close();

	cout << "3. ID가 서로 같은 객체의 개수: " << sameIdCnt << endl << endl;

#if DEBUG
	start = chrono::high_resolution_clock::now();
#endif

	for (int i = 0; i < DATA_COUNT; ++i) {
		players[i].sortP();
		over10A += players[i].isOver10A();
	}

#if DEBUG
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "수행 시간: " << duration.count() << "ms" << endl;
#endif

	std::cout << "4. 'a'가 10글자 이상인 Player 개수: " << over10A << endl << endl;

	int id;
	do {
		cout << "ID를 입력하세요: ";
		cin >> id;
#if DEBUG
		start = chrono::high_resolution_clock::now();
#endif
		find_player(id);
#if DEBUG
		end = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::milliseconds>(end - start);
		cout << "수행 시간: " << duration.count() << "ms" << endl;
#endif
	} while (true);
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
	vector<int> findScores;
	vector<string> findNames;
	findScores.reserve(10);
	findNames.reserve(10);

	auto iter = lower_bound(sortedByIDPlayersPtr.begin(), sortedByIDPlayersPtr.end(), playerId, [](const Player* p, int id) {
		return p->getId() < id;
		});

	if (iter == sortedByIDPlayersPtr.end() || (*iter)->getId() != playerId) {
		cout << "ID가 " << playerId << "인 Player가 없습니다." << endl << endl;
		return;
	}

	//=====================================================
	// ID 정렬 배열에서 해당 ID의 객체와 앞뒤 객체 출력
	// 동일 ID가 존재하는 경우 vector에 모두 저장
	cout << "ID 기준 정렬" << endl;
	if (iter != sortedByIDPlayersPtr.begin())
		cout << **(iter - 1) << endl;
	while ((*iter)->getId() == playerId && iter != sortedByIDPlayersPtr.end() - 1) {
		findScores.emplace_back((*iter)->getScore());
		findNames.emplace_back((*iter)->getName());
		cout << **iter++ << endl;
	}
	if ((*iter)->getId() == playerId && iter == sortedByIDPlayersPtr.end() - 1) {
		findScores.emplace_back((*iter)->getScore());
		findNames.emplace_back((*iter)->getName());
		cout << **iter << endl;
	}
	else if (iter != sortedByIDPlayersPtr.end())
		cout << **iter << endl;
	cout << endl;
	//=====================================================


	//=====================================================
	// 이름 정렬 배열에서 해당 ID의 객체와 앞뒤 객체 출력
	cout << "이름 기준 정렬" << endl;
	for (string target : findNames) {
		auto iterName = lower_bound(sortedByNamePlayersPtr.begin(), sortedByNamePlayersPtr.end(), target, [](const Player* p, const string& name) {
			return p->getName() < name;
			});

		// 1226773
		while (iterName != sortedByNamePlayersPtr.end()) {
			if ((*iterName)->getId() == playerId)
				break;
			++iterName;
		}

		if (iterName != sortedByNamePlayersPtr.begin())
			cout << **(iterName - 1) << endl;
		cout << **iterName << endl;
		if (iterName != sortedByNamePlayersPtr.end() - 1)
			cout << **(iterName + 1) << endl;
		cout << endl;
	}
	//=====================================================

	//=====================================================
	// 점수 정렬 배열에서 해당 ID의 객체와 앞뒤 객체 출력
	cout << "점수 기준 정렬" << endl;
	for (int target : findScores) {
		auto iterScore = lower_bound(sortedByScorePlayersPtr.begin(), sortedByScorePlayersPtr.end(), target, [](const Player* p, int score) {
			return p->getScore() < score;
			});

		while (iterScore != sortedByScorePlayersPtr.end()) {
			if ((*iterScore)->getId() == playerId)
				break;
			++iterScore;
		}

		if (iterScore != sortedByScorePlayersPtr.begin())
			cout << **(iterScore - 1) << endl;
		cout << **iterScore << endl;
		if (iterScore != sortedByScorePlayersPtr.end() - 1)
			cout << **(iterScore + 1) << endl;
		cout << endl;
	}
	//=====================================================
}