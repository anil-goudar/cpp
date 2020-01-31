#pragma once
#include<iostream>
class Cents {
	int m_cents = 10;
public:
	Cents(int cents);
	int getCents() const;
	friend Cents operator+(const Cents &c1, const Cents &c2);
};


class Fraction {
	int m_numerator;
	int m_denominator;
public:
	Fraction();
	Fraction(int num, int den);
	void print();
	friend Fraction operator*(const int &n, const Fraction& f1);
	friend Fraction operator*(const Fraction& f1, const int& n);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	int gcd(int a, int b);
	void reduce(int d);
};