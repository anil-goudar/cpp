#pragma once
#include<iostream>
#include<string>
using namespace std;

class Animal {
protected:
	string m_name;
	string m_speak;
	Animal(const string &name) : m_name(name) {}
public:
	const string& getName() const { return m_name; }
	virtual string speak() const { return "???"; }
};

class Cat : public Animal {
public:
	Cat(const string &name): Animal(name){}
	virtual string speak() const { return "Meow"; }
};

class Dog : public Animal {
public:
	Dog(const string &name): Animal(name) {}
	virtual string speak() const { return "Woof"; }
};


class Base {
public:
	virtual ~Base() {
		cout << "Calling ~Base()" << endl;
	}
};

class Derived : public Base {
private:
	int* m_array;
public:
	Derived(int len) {
		m_array = new int[len];
	}
	virtual ~Derived() {
		cout << "Calling ~Derived()" << endl;
		delete[] m_array;
	}
};


class Animal1 {
protected:
	string m_name;
public:
	Animal1(string name) : m_name(name) {}
	string getName() { return m_name; }
	virtual const char* speak() = 0;
};
const char* Animal1::speak() {
	return "buzz";
}