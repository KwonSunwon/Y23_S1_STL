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

void copy_players(); // players 배열을 정렬 배열에 각각 복사
void pointing_players();
void sort_players(); // 정렬 배열을 정렬
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
		//players[i].sortP();
		//over10A += players[i].isOver10A();

		idMap[players[i].getId()].emplace_back(&players[i]);
		/*if (idMap.find(players[i].getId()) == idMap.end())
			idMap[players[i].getId()] = 1;
		else
			idMap[players[i].getId()]++;*/
	}

	ifs.close();

	std::cout << "1. 마지막 Player" << endl
		<< players[DATA_COUNT - 1] << endl
		<< "저장된글자:" << players[DATA_COUNT - 1].getP() << endl << endl;;

	//start = chrono::high_resolution_clock::now();
	pointing_players();
	//end = chrono::high_resolution_clock::now();
	//cout << "포인팅 시간: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

	// 정렬도 생각보다 여전히 시간이 걸림
	// 시간을 더 줄일 수 있는 방법?
	sort_players();

	/*cout << "ID 정렬" << endl;
	for (const Player* p : sortedByIDPlayersPtr
		| views::take(3))
		cout << *p << endl;
	for (const Player* p : sortedByIDPlayersPtr
		| views::drop(DATA_COUNT - 3))
		cout << *p << endl;
	cout << endl;

	cout << "이름 정렬" << endl;
	for (const Player* p : sortedByNamePlayersPtr
		| views::take(3))
		cout << *p << endl;
	for (const Player* p : sortedByNamePlayersPtr
		| views::drop(DATA_COUNT - 3))
		cout << *p << endl;
	cout << endl;

	cout << "점수 정렬" << endl;
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

	std::cout << "2. Score가 가장 큰 Player" << endl
		<< *sortedByScorePlayersPtr[DATA_COUNT - 1] << endl
		<< "Player Socore 평균: " << static_cast<double>(sum) / DATA_COUNT << endl << endl;

	int sameIdCnt{ 0 };
	ofstream sameIdFile{ "같은아이디.txt" };
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

	// 파일 마지막 부분에 제대로 출력되지 않는 부분이 있음
	// 2345342 dwzgleeai 
	// 이런식으로 끝남
	// 중단점 넣고 확인해 봤을 때는 제대로 입력이 되는거 같은데
	// 자료가 너무 커서 그럴 수도 있나?
	// 아니면 파일에 쓰는 형식이 잘못되었을 수도 있음
	// -> charGPT 한테 물어보니까 파일이 완전히 닫히지 않아
	// 버퍼에 일부 데이터가 남아 제대로 출력이 안될 수 있다고 했는데
	// 진짜 파일 여는 것을 스코프로 묶어서 작업이 끝나면 사라지게 하니까
	// 정상적으로 작동함;;
	
	// 1149459
	cout << "3. ID가 서로 같은 객체의 개수: " << sameIdCnt << endl << endl;

	// 이 부분 시간 줄일 수 있는 방법 없을까?
	for (Player& p : players) {
		p.sortP();
		over10A += p.isOver10A();
	}

	std::cout << "4. 'a'가 10글자 이상인 Player 개수: " << over10A << endl << endl;


	//auto iterName = find_if(sortedByNamePlayersPtr.begin(), sortedByNamePlayersPtr.end(), [](const Player* p, const Player* ptr) {
		//return p == ptr;
		//});
	// 흠...
	// 생각해보니까 주소값을 가지고 찾는다고 해도 주소 값이 정렬된게 아니니까 결국 선형 탐색을 해야하는데
	// 그렇다면 주소값을 이용해서 찾는것보다 ID 정렬 배열에서 찾아낸 객체를 이용해서 객체 내용을 확인하고
	// 그걸 이용해서 각각 이진 탐색을 하는게 더 빠를거 같음

	// + 5번 과제 궁금증 추가
	// 만약에 같은 id를 객체가 두 개 이상 존재할 때
	// 해당 객체의 이름 정렬에서도 id에 해당하는 모든 객체에 대해서 해당 일을 해야 하는건가?

	for (const auto& p : sortedByIDPlayersPtr
		| views::drop(DATA_COUNT - 5)) {
		cout << *p << endl;
	}


	findPlayers.reserve(10);
	int id;
	do {
		cout << "ID를 입력하세요: ";
		cin >> id;
		find_player(id);
	} while (true);
}

// 복사 생각해보니까 깊은 복사를 하는게 아니라
// 포인터로 가리키기만 하면 옮겨야되는 데이터 수가 줄어드니까
// 더 빠른거 아냐?
// 속도 차이 엄청남;;
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
		cout << "ID가 " << playerId << "인 Player가 없습니다." << endl << endl;
		return;
	}

	//=====================================================
	// ID 정렬 배열에서 해당 ID의 객체와 앞뒤 객체 출력
	// 동일 ID가 존재하는 경우 vector에 모두 저장
	cout << "ID 기준 정렬" << endl;
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
	// 이름 정렬 배열에서 해당 ID의 객체와 앞뒤 객체 출력
	cout << "이름 기준 정렬" << endl;
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
	// 점수 정렬 배열에서 해당 ID의 객체와 앞뒤 객체 출력
	cout << "점수 기준 정렬" << endl;
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