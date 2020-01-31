#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<string_view>
#include <cstdlib>
#include<cmath>
using namespace std;
void readOne();
void readTwo();

void string_view_f1();
enum Items {
	HEALTHPORTIONS,
	TORCHES,
	ARROWS,
	MAXITEMS,
};

void countTotalItems(int* items);
struct Student {
	string name;
	int grade;
};
void programTwo();


enum CardSuits {
	CLUB,
	DIAMONDS,
	HEARTS,
	SPADES,
	MAXSUITS
};

enum CardRanks {
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

struct Card {
	CardSuits suit;
	CardRanks rank;
};

void printCard(const Card& card);
void printDeck(const std::array<Card, 52>& deck);


void swapCard(Card& c1, Card& c2);
int getRandomNumber(int , int);
void shuffleDeck(std::array<Card, 52>& deck);

class Point2d {
private:
	double m_x = 0.0;
	double m_y = 0.0;
public:
	Point2d(double x = 0, double y = 0);
	void print();
	double distanceTo(const Point2d& point);
	friend double distanceFrom(const Point2d& p1, const Point2d& p2);
};

class Monster {
public:
	enum MonsterType {
		MONSTER_DRAGON,
		MONSTER_GOBLIN,
		MONSTER_ORGE,
		MONSTER_ORC,
		MONSTER_SKELETON,
		MONSTER_TROLL,
		MONSTER_VAMPIRE,
		MONSTER_ZOMBIE,
		MAX_MONSTER_TYPES
	};
private:
	MonsterType m_monsterType;
	string m_name;
	string m_roar;
	int m_hp;
public:
	Monster(MonsterType monster, string name, string roar, int hp);
	string getMonsterType(MonsterType monster);
	void print();
};

class MonsterGenerator {

public:
	static Monster generateMonster();
	static int getRandomNumber(int min, int max);
};