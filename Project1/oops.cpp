#include "oops.h";

class DateClass {
	int m_year;
	int m_month;
	int m_day;

public:
	DateClass() {}
	DateClass(int year, int month, int day) {
		this->m_year = year;
		this->m_month = month;
		this->m_day = day;
	}
	void print() {
		cout << this -> m_year << "/" << this -> m_month << "/" << this->m_day << endl;
	}

	void copyFrom(const DateClass& d) {
		this->m_year = d.m_year;
		this->m_month = d.m_month;
		this->m_day = d.m_day;
	}
};


void ClassObject() {
	DateClass date(2019, 12, 29);
	date.print();
	DateClass date2;
	date2.copyFrom(date);
	date2.print();
}


class Point {
	int m_x;
	int m_y;
	int m_z;
public:
	void setValues(int x, int y, int z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print() {
		cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << endl;
	}

	bool isEqual(const Point& P) {
		if (m_x == P.m_x && m_y == P.m_y && m_z == P.m_z) {
			return true;
		}
		return false;
	}
};

void pointObject() {
	Point p;
	p.setValues(1, 2, 3);
	p.print();
	Point p2;
	p2.setValues(1, 2, 3);
	if (p.isEqual(p2)) {
		cout << "Point 1 and Point 2  are equal." << endl;
	}
	else {
		cout << "Point 1 and Point 2  are not equal." << endl;
	}
	Point p3;
	p3.setValues(3, 4, 5);
	if (p.isEqual(p3)) {
		cout << "Point 1 and Point 3  are equal." << endl;
	}
	else {
		cout << "Point 1 and Point 2  are not equal." << endl;
	}
}

void MyStack::reset() {
	m_size = 0;
}
bool MyStack::push(int x) {
	if (m_size >= 10) {
		return false;
	}
	m_array[m_size++] = x;
	return true;
}
int MyStack::pop() {
	if (m_size < 0) {
		cout << "stack is empty!" << endl;
		return 0;
	}
	return m_array[m_size--];
}
void MyStack::print() {
	if (m_size == 0) {
		cout << "Stack is empty!" << endl;
	}
	cout << "( ";
	for (int i = 0; i < m_size; i++) {
		cout << m_array[i] << " ";
	}
	cout << ")";
	cout << endl;
}

void Something::setValue(int value) { m_value = value; }
int Something::getValue() const{
	return m_value;
}

Accumulator::Accumulator() { m_value = 0; }
void Accumulator::add(int value) { m_value += value; }
void reset(Accumulator& ac) { ac.m_value = 0; }
int Accumulator::getValue() { return m_value; }