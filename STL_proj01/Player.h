#pragma once

class Player {
private:
	std::string name;
	int score;
	size_t id;
	size_t num;
	char* p;

public:
	Player();
	~Player();

	Player(Player& other);
	Player& operator=(Player& other);

	Player(Player&& other);
	Player& operator=(Player&& other);

	friend std::ostream& operator<<(std::ostream& os, const Player& p);

	friend std::istream& operator>>(std::istream& is, Player& p) {
		is.read(reinterpret_cast<char*>(&p), sizeof(Player));
		p.p = new char[p.num];
		is.read(p.p, p.num);
		return is;
	}

	std::string getName() const { return name; }
	int getScore() const { return score; }
	size_t getId() const { return id; }
	size_t getNum() const { return num; }
	char* getP() const { return p; }
};