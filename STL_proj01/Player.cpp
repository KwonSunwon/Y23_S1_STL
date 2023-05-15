#include <iostream>
#include <string>
#include <format>
#include <algorithm>
#include <numeric>
#include <span>
#include <execution>

#include "Player.h"

Player::Player()
{
	name = "";
	score = 1;
	id = 0;
	num = 0;
	p = nullptr;
}

Player::Player(std::string name, int score, size_t id, size_t num, char* p)
{
	this->name = name;
	this->score = score;
	this->id = id;
	this->num = num;
	this->p = new char[num];
	memcpy(this->p, p, num);

	//std::cout << "생성자 호출" << std::endl;
}

Player::~Player()
{
	delete[] p;

	//std::cout << "소멸자 호출" << std::endl;
}

Player::Player(Player& other)
{
	name = other.name;
	score = other.score;
	id = other.id;
	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	//std::cout << "복사 생성자 호출" << std::endl;
}

Player& Player::operator=(Player& other)
{
	if (this == &other)
		return *this;
	delete[] p;

	name = other.name;
	score = other.score;
	id = other.id;
	num = other.num;

	p = new char[num];
	memcpy(p, other.p, num);

	//std::cout << "복사 할당 연산자 호출" << std::endl;

	return *this;
}

Player::Player(Player&& other) noexcept
{
	name = other.name;
	score = other.score;
	id = other.id;
	num = other.num;
	p = other.p;

	other.name = "";
	other.score = 0;
	other.id = 0;
	other.num = 0;
	other.p = nullptr;

	//std::cout << "이동 생성자 호출" << std::endl;
}

Player& Player::operator=(Player&& other) noexcept
{
	if (this == &other)
		return *this;

	delete[] p;

	name = other.name;
	score = other.score;
	id = other.id;
	num = other.num;

	p = other.p;
	other.name = "";
	other.score = 0;
	other.id = 0;
	other.num = 0;
	other.p = nullptr;

	//std::cout << "이동 할당 연산자 호출" << std::endl;

	return *this;
}

void Player::sortP() 
{
	std::sort(p, p + num);
}

bool Player::isOver10A() const
{
	//return std::count_if(p, p + num, [](char c) { return c == 'a'; }) >= 10;
	if(num < 10) return false;
	return p[9] == 'a';
	// 문제 조건에서 정렬을 하라고 했으므로, 10번째 원소가 'a'인지만 확인하면 된다.
}

long long sumScore(const std::span<Player>& players)
{
	//return std::reduce(std::execution::par, players.begin(), players.end(), 0LL, [](long long sum, const Player& p) { return sum + p.score; });
	return std::accumulate(players.begin(), players.end(), 0LL, [](long long sum, const Player& p) { return sum + p.score; });
}