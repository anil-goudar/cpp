#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string m_name;
	int m_age;

	Person(string name = "", int age = 0) :
		m_name(name), m_age(age) {
		cout << "Person" << endl;
	}
	string getName() const { return m_name; }
	int getAge() const { return m_age; }
};

class BaseballPlayer:public Person {
public:
	double m_battingaverage;
	int m_homeruns;
	BaseballPlayer(double average = 0.0, int homeruns = 0) :
		m_battingaverage(average), m_homeruns(homeruns) {
		this->m_name = "Anil";
		this->m_age = 26;
		cout << "Baseball player" << endl;
	}
};

class Fruit {
private:
	string m_name;
	string m_color;
public:
	Fruit(string name = "", string color = "") :
		m_name(name), m_color(color) {}
	string getName() const { return m_name; }
	string getColor() const { return m_color; }
};

class Apple : public Fruit {
public:
	Apple(string name="apple", string color = "red") :
		Fruit("apple", color) {}
	void print()const {
		cout << "Apple(" << getName() << ", " << getColor() <<  ")" << endl;
	}
};
class GrannySmith : public Apple {
public:
	GrannySmith(string name = "granny smith", string color = "green")
		: Apple(name, color) {}
};
class Banana : public Fruit {
public:
	Banana(string name = "banana", string color = "yellow") :
		Fruit(name, color) {}
	void print() const {
		cout << "Banana(" << getName() << ", " << getColor()  << ")" << endl;
	}
};


class Base {
protected:
	int m_value;
public:
	Base(int value) :
		m_value(value) {}
	void identify() {
		cout << "I am in base\n";
	}
};

class Derived : public Base {
public:
	Derived(int n): Base(n){}
	int getValue() { return m_value; }
	void identify() {
		cout << "I am in derived\n";
	}
};

class Creature {
protected:
	string m_name;
	char m_symbol;
	int m_hp;
	int m_attackDamage;
	int m_gold;
public:
	Creature() {}
	Creature(string name, char sym, int hp, int dmg, int gold)
		: m_name(name), m_symbol(sym), m_hp(hp), m_attackDamage(dmg), m_gold(gold) {}
	void setName(string name) {
		m_name = name;
	}
	string getName() const { return m_name; }

	void setSymbol(char ch) {
		m_symbol = ch;
	}
	char getSymbol() const { return m_symbol; }

	void setHP(int hp) {
		m_hp = hp;
	}
	int getHP() const { return m_hp; }

	void setAttackDamage(int dmg) {
		m_attackDamage = dmg;
	}
	int getAttackDamage() const { return m_attackDamage; }

	void setGold(int gold) {
		m_gold = gold;
	}
	int getGold() const { return m_gold; }

	void reduceHealth(int hp) {
		m_hp -= hp;
	}
	bool isDead() {
		if (m_hp <= 0)
			return true;
		return false;
	}
	void addGold(int gold) {
		m_gold += gold;
	}
};


class Player : public Creature {
protected:
	int m_level;
public:
	Player(string name)
		:Creature(name, '@', 10, 1, 0), m_level(1) {
	}
	void levelUp() {
		m_level += 1;
		m_attackDamage += 1;
	}
	bool hasWon() {
		if (m_level == 20) {
			return true;
		}
		else
			return false;
	}
	int getLevel() const { return m_level; }
};

class Monster : public Creature {
public:
	enum Type {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	Monster(){}
	Monster(Monster::Type type) {
		if (type == DRAGON) {
			m_name = "dragon";
			m_symbol = 'D';
			m_hp = 20;
			m_attackDamage = 4;
			m_gold = 100;
		}
		else if (type == ORC) {
			m_name = "orc";
			m_symbol = 'o';
			m_hp = 4;
			m_attackDamage = 2;
			m_gold = 25;
		}
		else {
			m_name = "slime";
			m_symbol = 's';
			m_hp = 1;
			m_attackDamage = 1;
			m_gold = 10;
		}
	}

	static Monster::Type getRandomMonster() {
		int min = 0;
		int max = MAX_TYPES-1;
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
		return static_cast<Monster::Type>(min + static_cast<int>( (max - min + 1) * (std::rand() * fraction)));
	}
};
void attackMonster(Player& player, Monster& monster);
void attackPlayer(Player& player, Monster& monster);
void fightMonster(Player &player, Monster &monster) {
	bool play = true;
	while (play) {
		char choose;
		cout << "(R)un or (F)ight: ";
		cin >> choose;
		if (choose == 'f') {
			attackMonster(player, monster);
			play = false;
		}
	}
}


void attackMonster(Player& player, Monster& monster) {
	monster.setHP(monster.getHP() - player.getAttackDamage());
	if (monster.getHP() == 0) {
		player.setGold(monster.getGold() + player.getGold());
		player.levelUp();
		cout << "You won!!" << endl;
		cout << "You earned " << player.getGold() << " golds." << endl;
	}
	else {
		attackPlayer(player, monster);
	}
}

void attackPlayer(Player& player, Monster& monster) {
	int playerCurHP = player.getHP();
	int monsterDmg = monster.getAttackDamage();
	int playerNewHP = playerCurHP - monsterDmg;
	if (playerNewHP > 0) {
		player.setHP(playerNewHP);
	}
	else {
		cout << " You loose and your level is: " << player.getLevel() << " and you have " <<
			player.getGold() << " gold." << endl;
	}
}