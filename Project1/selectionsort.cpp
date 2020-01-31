#include "sort.h";
#include "helper.h";
void selectionSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[min_index]) {
				min_index = j;
			}
		}
		int temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
}

void bubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int j = i + 1;
		for (; j < size; j++) {
			if (array[i] > array[j]) {
				swap(&array[i], &array[j]);
			}
		}
	}
}