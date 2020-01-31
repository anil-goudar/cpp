#include "sort.h"
#include "helper.h"
//#include "ch6header.h"
#include "oops.h"
#include "timer.h"
#include "overloading.h"
#include "intarray.h"
//#include "inheritance.h"
#include "virtualfunctions.h"
#include <chrono>
#include <ctime>
using namespace std;

class StaticEx {
	static int s_value;
public:
	static int getSValue() { return s_value; }
	int getValue() { return s_value; }
};
int StaticEx::s_value = 1;
class Storage;
class Display {
	bool m_displayIntFirst;
public:
	Display(bool displayInfFirst) { m_displayIntFirst = displayInfFirst; }
	void displayItem(const Storage& storage);
};
class Storage {
	int m_value;
	double m_dValue;
public:
	Storage(int value, double dValue) {
		m_value = value;
		m_dValue = dValue;
	}
	friend void Display::displayItem(const Storage& storage);
};
void Display::displayItem(const Storage& storage) {
	if (m_displayIntFirst)
		cout << storage.m_value << " " << storage.m_dValue << endl;
	else
		cout << storage.m_dValue << " " << storage.m_value << endl;
}

int main() {
	/*const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	auto t1 = std::chrono::high_resolution_clock::now();
	selectionSort(array, length);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout << "Selection sort duration is: " << duration<< endl;
	print(array, length);

	auto t3 = std::chrono::high_resolution_clock::now();
	bubbleSort(array, length);
	auto t4 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
	cout << "Bubble sort duration is: " << duration << endl;
	print(array, length);*/

	//cout << "Chapter 6 Begins: " << endl;
	////readOne();
	////readTwo();
	//string_view_f1();
	//cout << "Chapter 6 ends: " << endl;

	//int* x = NULL;
	//print(x);
	//print(0);
	//print(NULL);
	//arrayMemoryAllocation();

	//char name[] = "Anil";
	//int len = static_cast<int>(std::size(name));
	//int vowels = 0;
	//for (char* ch = &name[0]; ch < (&name[0] + len); ch++) {
	//	if (isVowel(*ch)) {
	//		vowels += 1;
	//	}
	//}
	//cout << name << " has " << vowels << " vowels." << endl;
	//auto numVowels = std::count_if(std::begin(name), std::end(name), isVowel);
	//cout << name << " has " << numVowels << " vowels." << endl;

	////pointers();
	////constPointers();
	//referenceVariables();
	//dereferanceStruct();
	////foreach();
	////voidPtr();
	//stdarray();
	/*int items[MAXITEMS] = { 2,5,10 };
	countTotalItems(items);
	programTwo();*/
	//srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	//rand(); // If using Visual Studio, discard first random value
	//std::array<Card, 52> deck;
	//using index_t = std::array<Card, 52>::size_type;
	//index_t card = 0;
	//for(int suit = 0; suit < MAXSUITS; suit++)
	//	for (int rank = 0; rank < MAX_RANKS; rank++) {
	//		deck[card].rank = static_cast<CardRanks>(rank);
	//		deck[card].suit = static_cast<CardSuits>(suit);
	//		card++;
	//	}
	////printDeck(deck);
	//shuffleDeck(deck);
	//ClassObject();

	//pointObject();

	//MyStack stack;
	//stack.reset();
	//stack.print();
	//stack.push(5);
	//stack.push(3);
	//stack.push(8);
	//stack.print();
	//stack.pop();
	//stack.print();
	//Timer t;
	//const Something something;
	//cout << something.getValue();
	//cout << StaticEx::getSValue();
	//cout << endl << "Friend Functions: " << endl;
	//Accumulator ac;
	//ac.add(20);
	//cout << ac.getValue() << endl;
	//reset(ac);
	//cout << ac.getValue() << endl;
	//Storage storage(5, 6.7);
	//Display display(false);
	//display.displayItem(storage);
	//cout << "time elapsed: " << t.elapsed() << " seconds" << endl;
	//Point2d first;
	//Point2d second(3.0, 4.0);
	//first.print();
	//second.print();
	//std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
	//std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
	//srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	//rand();
	//Monster m = MonsterGenerator::generateMonster();
	//m.print();

	/*Cents c1(100);
	Cents c2(200);
	Cents c3 = c1 + c2;
	cout << "Total cents: " << c3.getCents() << endl;

	Fraction f1(2, 5);
	f1.print();
	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();*/

	//IntArray array(10);
	//for (int i{ 0 }; i < array.getlength(); ++i)
	//	std::cout << array[i] << ' ';
	//cout << endl;
	//for (int i{ 0 }; i < 10; ++i)
	//	array[i] = i + 1;
	//for (int i{ 0 }; i < array.getlength(); ++i)
	//	std::cout << array[i] << ' ';
	//cout << endl;

	//// Resize the array to 8 elements
	//array.resize(8);
	//for (int i{ 0 }; i < array.getlength(); ++i)
	//	std::cout << array[i] << ' ';
	//cout << endl;

	//array.insertBefore(482,-12);
	//for (int i{ 0 }; i < array.getlength(); ++i)
	//	std::cout << array[i] << ' ';
	//cout << endl;

	/*BaseballPlayer bal(23.4, 89);
	cout << bal.getName() <<endl;
	const Apple a{ "Red delicious", "red", 4.2 };
	a.print();
	const Banana b{ "Cavendish", "yellow" };
	b.print();

	Base base(5);
	base.identify();
	Derived derived(10);
	derived.identify();*/


	/*Apple a{ "red" };
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";*/

	//Creature o{ "orc", 'o', 4, 2, 10 };
	//o.addGold(5);
	//o.reduceHealth(1);
	//std::cout << "The " << o.getName() << " has " << o.getHP() << " health and is carrying " << o.getGold() << " gold.\n";
	//cout << "Enter your name: ";
	//string name;
	//cin >> name;
	//Player p(name);
	//cout << "Welcome, " << p.getName() << "." << endl;
	//cout << "You have " << p.getHP() << " health and are carrying " << p.getGold() << " gold." << endl;


	//std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	//std::rand(); // get rid of first result

	//Monster m{ Monster::getRandomMonster() };
	//cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").";

	//fightMonster(p, m);
	//
	/*Cat cat("Fred");
	cout << "Cat is named " << cat.getName() << ", and it says " << cat.speak() << endl;
	
	Dog dog("Garbo");
	cout << "Dog is named " << dog.getName() << ", and it says " << dog.speak() << endl;

	Animal* pAnimal = &cat;
	cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << endl;

	pAnimal = &dog;
	cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << endl;

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;*/

	/*try {
		throw - 1;
	}
	catch (int x) {
		std::cerr << "We caught int exception\n";
	}
	catch (double x) {
		cerr << "We caught double exception\n";
	}
	int a;
	char c;
	cin >> a >> c;
	cout << c << a;*/
	variable_size();
	return 0;
}