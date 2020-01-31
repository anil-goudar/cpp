#pragma once
#include <iostream>
using namespace std;

void ClassObject();
void pointObject();


class MyStack {
	int m_array[10];
	int m_size;
public:
	void reset();
	bool push(int x);
	int pop();
	void print();
};


class Something {
public:
	int m_value;
	Something() :m_value(0) {}
	void setValue(int value);
	int getValue()const;
};


class Accumulator {
private:
	int m_value;
	friend void reset(Accumulator& ac);
public:
	Accumulator();
	void add(int value);
	int getValue();
};