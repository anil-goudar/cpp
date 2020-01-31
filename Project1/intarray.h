#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <cassert>
class IntArray {
private:
	int m_length{};
	int* m_data{};
public:
	IntArray() = default;

	IntArray(int length): m_length(length) {
		assert(length >= 0);
		if (length > 0) {
			m_data = new int[m_length] {};
		}
	}

	void erase() {
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[] (int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getlength() const {
		return m_length;
	}

	void resize(int newLength) {
		if (m_length == newLength)
			return;
		if (newLength <= 0) {
			erase();
			return;
		}
		int* data = new int[newLength];
		for (int i = 0; i < newLength; i++) {
			if (i <= m_length) {
				data[i] = m_data[i];
			}
			else {
				data[i] = 0;
			}
		}
		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int x, int index) {
		assert(index >= 0 && index <= m_length);
		int* data = new int[m_length + 1];
		for (int i = 0; i < index; i++) {
			data[i] = m_data[i];
		}
		data[index] = x;
		for (int i = index; i < m_length; i++) {
			data[i + 1] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
		m_length += 1;
	}
	~IntArray() {
		delete[] m_data;
	}
};
#endif // !INTARRAY_H
