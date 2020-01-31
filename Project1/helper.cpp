#include "helper.h";
#include <iostream>
using namespace std;
typedef struct Person {
	std::string name;
	int age;
} Anil;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void print(int x) {
	cout << "print(int) : " << x << endl;
}

void print(int* x) {
	if (!x) {
		cout << "print(int*) : null "<< endl;
	}
	else {
		cout << "print(int*) : " << *x << endl;
	}
}

void arrayMemoryAllocation() {
	int array[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		cout << "address of " << (i + 1) << " element is : " << &array[i] << endl;
	}
}

bool isVowel(char ch) {
	switch (ch) {
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
		return true;
	default:
		return false;
	}
}


void pointers() {
	//int* ptr = new(std::nothrow) int;
	//if (ptr) {
	//	*ptr = 4;
	//	cout << *ptr << " is placed at :" << ptr;
	//	//deallocating the memory
	//	delete ptr;
	//	// ptr becomes dangling pointer, make it always null pointer.
	//	ptr = 0;
	//	cout << ptr << endl;
	//}

	cout << "Enter the size of the array: ";
	int len;
	cin >> len;
	string* ptr = new(std::nothrow) std::string[len];
	if (ptr) {
		cout << "enter array elements: ";
		for (int i = 0; i < len; i++) {
			cin >> ptr[i];
		}
		std::sort(ptr, ptr + len);
		cout << "sorted array is: " << endl;
		for (int i = 0; i < len; i++)
		{
			cout << ptr[i] << endl;
		}
	}
}

void constPointers() {
	const int value = 5;
	const int* ptr = &value;
	int value2 = 10;
	int* const ptr2 = &value2;
	cout << "Value : " << value << " Ptr is: " << *ptr << endl;
	cout << "Value2 : " << value2 << " Ptr2 is: " << *ptr2 << endl;
	value2 = 203;
	cout << "Value2 : " << value2 << " Ptr2 is: " << *ptr2 << endl;
}

void referenceVariables() {
	int v = 5;
	int& ref = v;
	cout << "value: " << v << " and reference is: " << ref <<endl;
	v = 6;
	cout << "value: " << v << " and reference is: " << ref << endl;
	ref = 7;
	cout << "value: " << v << " and reference is: " << ref << endl;
	const int y = 7;
	const int& ref2 = y;
}

void dereferanceStruct() {
	Anil anil;
	Anil* ptr = &anil;
	ptr->name = "Anil";
	ptr->age = 26;
	cout << "Name: " << ptr->name <<endl;
	cout << "Age: " << anil.age << endl;
}

void foreach() {
	int array[] = { 1,2,3,4,5,6,7,8 };
	for (auto n : array) {
		cout << n << " ";
	}
	cout << endl;
	string names[] = { "Alex", "Betty", "Caroline", "Dave", "Emily" };
	string name;
	cout << "Enter a name: ";
	cin >> name;
	bool found = false;
	for (auto is : names) {
		if (strcmp(is.c_str(), name.c_str()) == 0) {
			found = true;
			cout << name << " was found.";
			break;
		}
	}
	if (!found) {
		cout << name << " was not found.";
	}
}

void voidPtr() {
	int nValue = 10;
	float fValue = 10.23;
	Anil anil;
	anil.age = 23;
	void* ptr;
	ptr = &nValue;
	cout <<*static_cast<int*>(ptr) << endl;
	cout <<*static_cast<float*>(ptr) << endl;
}
void stdarray() {
	std::array<float, 3> a = { 9.0, 2.13, 3.2 };
	cout << "Length : " << a.size() << endl;
	cout << sizeof(a.size()) << endl;

	sort(a.begin(), a.end());
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	sort(a.rbegin(), a.rend());
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
}

void variable_size() {
	int n_a;
	int n_q;
	std::vector<std::vector<int>> arr;
	cin >> n_a >> n_q;
	cout << n_a << "sds" << n_q;
}