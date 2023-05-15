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
	Player(std::string, int, size_t, size_t, char*);
	~Player();

	Player(Player& other);
	Player& operator=(Player& other);

	Player(Player&& other) noexcept;
	Player& operator=(Player&& other) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Player& p) {
		os << std::format("이름:{:<15}, 아이디:{:<10}, 점수:{:<10}, 자원수:{:<10}", p.name, p.id, p.score, p.num);
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Player& p) {
		is.read(reinterpret_cast<char*>(&p), sizeof(Player));
		p.p = new char[p.num];
		is.read(p.p, p.num);
		//std::sort(p.p, p.p + p.num);
		return is;
	}

	std::string getName() const { return name; }
	int getScore() const { return score; }
	size_t getId() const { return id; }
	size_t getNum() const { return num; }
	char* getP() const { return p; }

	void sortP();
	bool isOver10A() const;

	friend long long sumScore(const std::span<Player>& players);
};