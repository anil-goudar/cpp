#include "overloading.h";

Cents::Cents(int cents) : m_cents(cents) {}
int Cents::getCents() const { return m_cents; }

Cents operator+(const Cents &c1, const 
	Cents &c2) {
	int total = c1.getCents() + c2.getCents();
	return Cents(total);
}

Fraction::Fraction() {
	m_numerator = 0;
	m_denominator = 1;
}
Fraction::Fraction(int num, int den) : m_numerator(num), m_denominator(den) {}
void Fraction::print() {
	reduce(gcd(m_numerator, m_denominator));
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}

Fraction operator* (const int& n, const Fraction& f) {
	int r_num = n * f.m_numerator;
	return Fraction(r_num, f.m_denominator);
}

Fraction operator* (const Fraction& f, const int &n) {
	int r_num = n * f.m_numerator;
	return Fraction(r_num, f.m_denominator);
}

Fraction operator* (const Fraction& f1, const Fraction& f2) {
	int r_num = f1.m_numerator * f2.m_numerator;
	int r_den = f1.m_denominator * f2.m_denominator;
	return Fraction(r_num, r_den);
}

int Fraction::gcd(int a, int b) {
	return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
}

void Fraction::reduce(int d) {
	m_numerator = m_numerator / d;
	m_denominator = m_denominator / d;
}