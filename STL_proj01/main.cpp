#include <iostream>
#include <array>
#include <fstream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include "Player.h"

#define DATA_COUNT 2'000'000

using namespace std;

array<Player, DATA_COUNT> players;

array<Player, DATA_COUNT> sortedByIDPlayers;
array<Player, DATA_COUNT> sortedByNamePlayers;
array<Player, DATA_COUNT> sortedByScorePlayers;

int main()
{
	ifstream ifs("2023 STL 과제 파일", std::ios::binary);

	if (!ifs) {
		cerr << "파일을 열 수 없습니다." << endl;
		exit(1);
	}

	int maxScore{ numeric_limits<int>::min() };
	Player* maxPlayer{ nullptr };
	for (int i = 0; i < DATA_COUNT; ++i) {
		ifs >> players[i];
		int tempScore{ players[i].getScore() };
		if (maxScore < tempScore) {
			maxScore = tempScore;
			maxPlayer = &players[i];
		}
	}
	std::cout << "1. 마지막 Player" << endl
		<< players[DATA_COUNT - 1] << endl << endl;

	long long sum{ accumulate(players.begin(), players.end(), 0, [](long long total, const Player& p) {
			return total + p.getScore();
			}) };
	std::cout << "2. Score가 가장 큰 Player" << endl
		<< *maxPlayer << endl
		<< "Player Socore 평균: " << static_cast<double>(sum) / DATA_COUNT << endl << endl;

	sortedByIDPlayers = players;
	sortedByNamePlayers = players;
	sortedByScorePlayers = players;

	ranges::sort(sortedByIDPlayers, [](const Player& a, const Player& b) {
		return a.getId() < b.getId();
		});
	ranges::sort(sortedByNamePlayers, [](const Player& a, const Player& b) {
		return a.getName() < b.getName();
		});
	ranges::sort(sortedByScorePlayers, [](const Player& a, const Player& b) {
		return a.getScore() < b.getScore();
		});

	std::cout << "ID 정렬" << endl;
	for (auto& p : sortedByIDPlayers
		| views::take(10))
		std::cout << p << endl;
	std::cout << endl;

	std::cout << "이름 정렬" << endl;
	for (auto& p : sortedByNamePlayers
		| views::take(10))
		std::cout << p << endl;
	std::cout << endl;

	std::cout << "점수 정렬" << endl;
	for (auto& p : sortedByScorePlayers
		| views::take(10))
		std::cout << p << endl;
	std::cout << endl;

	std::cout << "작업 완료" << endl;

}