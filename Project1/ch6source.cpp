#include "ch6header.h"
#include <array>
void readOne() {
	char ch[5];
	cout << "Enter your full name: ";
	cin >> ch;
	cout << "You entered : " << ch << endl;
}

void readTwo() {
	char ch[5];
	cout << "Enter your full name: ";
	cin.getline(ch, std::size(ch));
	cout << "You entered : " << ch << endl;
}

void string_view_f1() {
	char text[] = "Hello";
	std::string str(text);
	std::string more(str);
	cout << text << ' ' << str << ' ' << more << endl;
	more[3] = '3';
	cout << text << ' ' << str << ' ' << more << endl;
}

void countTotalItems(int* items) {
	int itemc = 0;
	for (int i = 0; i < MAXITEMS; i++) {
		itemc += items[i];
	}
	cout << "Total items : " << itemc << endl;
}
bool compare(Student a, Student b) {
	return (a.grade > b.grade);
}

void programTwo() {
	int n;
	cout << "Enter the number of students: ";
	cin >> n;
	Student* students = new Student[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the details of student - " << i + 1 << " : ";
		cin >> students[i].name >> students[i].grade;
	}
	std::sort(students, students + n, compare);
	for (int i = 0; i < n; i++) {
		students += i;
		cout << students->name << " and " << students->grade << endl;
	}
	delete[] students;
}

void printCard(const Card& card) {
	switch (card.rank)
	{
	case RANK_2:		std::cout << '2'; break;
	case RANK_3:		std::cout << '3'; break;
	case RANK_4:		std::cout << '4'; break;
	case RANK_5:		std::cout << '5'; break;
	case RANK_6:		std::cout << '6'; break;
	case RANK_7:		std::cout << '7'; break;
	case RANK_8:		std::cout << '8'; break;
	case RANK_9:		std::cout << '9'; break;
	case RANK_10:		std::cout << 'T'; break;
	case RANK_JACK:		std::cout << 'J'; break;
	case RANK_QUEEN:	std::cout << 'Q'; break;
	case RANK_KING:		std::cout << 'K'; break;
	case RANK_ACE:		std::cout << 'A'; break;
	}

	switch (card.suit)
	{
	case CLUB:		std::cout << 'C'; break;
	case DIAMONDS:	std::cout << 'D'; break;
	case HEARTS:	std::cout << 'H'; break;
	case SPADES:	std::cout << 'S'; break;
	}
}

void printDeck(const std::array<Card, 52>& deck) {
	for (auto card : deck) {
		printCard(card);
		cout << endl;
	}
}

int getRandomNumber(int min=1, int max=52)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; 
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void swapCard(Card& c1, Card& c2) {
	Card temp;
	temp = c1;
	c1 = c2;
	c2 = temp;
}
void shuffleDeck(std::array<Card, 52>& deck) {
	for (auto card : deck) {
		using index_t = std::array<Card, 52>::size_type;
		index_t randomidx = static_cast<std::array<Card, 52>::size_type>(getRandomNumber() - 1);
		Card random = deck[randomidx];
		swapCard(card, random);
	}
}


Point2d::Point2d(double x, double y) : m_x(x), m_y(y) {}
void Point2d::print() {
	cout << "Point2d (" << m_x << ", " << m_y << ")" << endl;
}
double Point2d::distanceTo(const Point2d& point) {
	return static_cast<double>(sqrt((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y)));
}

double distanceFrom(const Point2d& p1, const Point2d& p2) {
	return static_cast<double>(sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y)));
}

Monster::Monster(MonsterType monster, string name, string roar, int hp) : m_monsterType(monster),
m_name(name), m_roar(roar), m_hp(hp) {}
string Monster::getMonsterType(MonsterType monster) {
	switch (monster) {
	case MonsterType::MONSTER_DRAGON: return static_cast<std::string>("dragon");break;
	case MonsterType::MONSTER_GOBLIN: return static_cast<std::string>("goblin");break;
	case MonsterType::MONSTER_ORC: return static_cast<std::string>("orc");break;
	case MonsterType::MONSTER_ORGE: return static_cast<std::string>("orge");break;
	case MonsterType::MONSTER_SKELETON: return static_cast<std::string>("skeleton");break;
	case MonsterType::MONSTER_TROLL: return static_cast<std::string>("troll");break;
	case MonsterType::MONSTER_VAMPIRE: return static_cast<std::string>("vampire");break;
	case MonsterType::MONSTER_ZOMBIE: return static_cast<std::string>("zombie");break;
	}
	return "???";
}
void Monster::print() {
	cout << m_name << " the " << getMonsterType(m_monsterType) << " has " << m_hp << " hit points and says " << m_roar << endl;
}

Monster MonsterGenerator::generateMonster() {
	Monster::MonsterType mType = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MonsterType::MAX_MONSTER_TYPES-1));
	int hp = getRandomNumber(1, 100);
	
	return Monster(Monster::MonsterType::MONSTER_SKELETON, "Bones", "*rattle*", 4);
}

int MonsterGenerator::getRandomNumber(int min, int max) {
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}