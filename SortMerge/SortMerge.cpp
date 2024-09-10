#include <iostream>

void merge_sort(int* arr, int size);
void merge(int* arr, int* arr1, int size, int size1);
void print(int* arr, int size);

int main() {

	setlocale(LC_ALL, "");

	int* arr = new int[10]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	int* arr1 = new int[15] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	int* arr2 = new int[18] { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
	
	std::cout << "Исходный массив:        ";
	print(arr, 10);
	merge_sort(arr, 10);
	std::cout << "Отсортированный массив: ";
	print(arr, 10);

	std::cout << "Исходный массив:        ";
	print(arr1, 15);
	merge_sort(arr1, 15);
	std::cout << "Отсортированный массив: ";
	print(arr1, 15);

	std::cout << "Исходный массив:        ";
	print(arr2, 18);
	merge_sort(arr2, 18);
	std::cout << "Отсортированный массив: ";
	print(arr2, 18);

	

	return 0;
}


void merge_sort(int* arr, int size) {

	if (size == 1) {
		return;
	}
	int left_size = size / 2;
	int righ_size = size - left_size;
	
	merge_sort(arr, left_size);
	merge_sort((arr + left_size), righ_size);
	merge(arr, (arr + left_size), left_size, righ_size);
	
}

void merge(int* arr, int* arr1, int size, int size1) {
	int size_full = size + size1;
	int* arr2 = new int[size_full]{0};
	int a = 0, a1 = 0, a2 = 0;
	while (a < size || a1 < size1) 	{
		if (a == size) {
			arr2[a2] = arr1[a1];
			a1++;
		}
		else if (a1 == size1) {
			arr2[a2] = arr[a];
			a++;
		}
		else {
			if (arr[a] < arr1[a1]) {
				arr2[a2] = arr[a];
				a++;
			} else {
				arr2[a2] = arr1[a1];
				a1++;
			}
		}
		a2++;

	}
	for (int i = 0; i < size_full; ++i) {
		arr[i] = arr2[i];

	}
	delete[] arr2;
	
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i < size - 1) std::cout << " ";
	}
	std::cout << "\n";
}