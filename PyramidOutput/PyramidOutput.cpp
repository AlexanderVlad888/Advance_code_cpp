#include <iostream>

void printMatrix(const int* arr, int size);
void printPyramid(const int* arr, int size);
int intLog(int value);

int main()
{
    
    setlocale(LC_ALL, "");

    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(arr) / sizeof(int);

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = sizeof(arr2) / sizeof(int);

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size3 = sizeof(arr3) / sizeof(int);


    printPyramid(arr, size);
    std::cout << "\n";
    printPyramid(arr2, size2);
    std::cout << "\n";
    printPyramid(arr3, size3);

    
}

void printMatrix(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << " ";
    }
    std::cout << "\n";
}

void printPyramid(const int* arr, int size) {
    std::cout << "Исходный массив: ";
    printMatrix(arr, size);
    std::cout << "Пирамида:\n";

    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            std::cout << intLog(i + 1) << " root " << arr[i] << "\n";
        }
        else if (i % 2 != 0) {
            std::cout << intLog(i + 1) << " left(" << arr[i / 2] << ") " << arr[i] << "\n";
        }
        else {
            std::cout << intLog(i + 1) << " right(" << arr[i / 2 - 1] << ") " << arr[i] << "\n";
        }
    }
}

int intLog(int value) {
    int result = 0;
    while (value >= 2) {
        value /= 2; 
        result++; 
    }
    return result; 
}
