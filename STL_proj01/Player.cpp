#include <iostream>
#include <string>
#include <format>
#include <algorithm>

#include "Player.h"

Player::Player()
{
	name = "";
	score = 0;
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
}

Player::~Player()
{
	delete[] p;
}

Player::Player(Player& other)
{
	name = other.name;
	score = other.score;
	id = other.id;
	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);
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
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << std::format("이름:{:<15}, 아이디:{:<10}, 점수:{:<10}, 자원수:{:<10}", p.name, p.id, p.score, p.num);
	return os;
}

void Player::sortP() 
{
	std::sort(p, p + num);
}

bool Player::isOver10A() 
{
	return std::count_if(p, p + num, [](char c) { return c == 'a'; }) >= 10;
}