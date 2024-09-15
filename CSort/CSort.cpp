#include <iostream>

void print(int* arr, int size);
int max(int* arr, int size);
int min(int* arr, int size);
void countSort(int* arr, int size);


int main() {

    setlocale(LC_ALL, "");

    int arr[] = { 8, 6, -68, 35, 63, 125,7, 1, 20003, 4, 0, 55, -17 };
    int arr1[] = { 3, 43, 38, 29, 18, 7, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int size = sizeof(arr) / sizeof(int);
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    int size3 = sizeof(arr3) / sizeof(int);

    std::cout << "Исходный массив:        ";
    print(arr, size);
    countSort(arr, size);
    std::cout << "Отсортированный массив: ";    
    print(arr, size);

    std::cout << "Исходный массив:        ";
    print(arr1, size1);
    countSort(arr1, size1);
    std::cout << "Отсортированный массив: ";
    print(arr1, size1);
   
    std::cout << "Исходный массив:        ";
    print(arr2, size2);
    countSort(arr2, size2);
    std::cout << "Отсортированный массив: ";
    print(arr2, size2);

    std::cout << "Исходный массив:        ";
    print(arr3, size3);
    countSort(arr3, size3);
    std::cout << "Отсортированный массив: ";
    print(arr3, size3);

}


void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int max(int* arr, int size) {
    int max = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int min(int* arr, int size) {
    int min = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void countSort(int* arr, int size) {
    int max_size = max(arr, size);
    int shift = (min(arr, size) < 0) ? min(arr, size) * -1 : 0;
    int* arr2 = new int[max_size + shift + 1] {0};

    for (int i = 0; i < size; i++) {
        arr2[arr[i] + shift]++;
    }

    for (int i = 0, k = 0; i < max_size + shift + 1; ++i) {
        for (int j = 0; j < arr2[i]; ++j) {
            if (arr2[i] != 0) {
                arr[k] = i - shift;
                k++;
            }

        }

    }
    delete[] arr2;

}




