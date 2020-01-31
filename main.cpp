#include<iostream>
#include "selectionSort.cpp"
void selectionSort(int a[], int n);
int main() {
	int arr[3] = { 1,10,2 };
	selectionSort(arr, 3);
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}