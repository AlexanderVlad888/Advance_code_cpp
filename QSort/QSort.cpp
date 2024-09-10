#include <iostream>

void quick_sort(int* arr, int size);
void quick_sort_rec(int* arr, int low, int high);
int pivoting(int* arr, int low, int high);
void print(int* arr, int size);


int main()
{
    setlocale(LC_ALL, "");

    int arr1[] = {3, 43, 38, 29, 18, 7, 57, 61, 2, 33};
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    int size3 = sizeof(arr3) / sizeof(int);
  

    std::cout << "Исходный массив:        ";
    print(arr1, size1);
    quick_sort(arr1, size1);
    std::cout << "Отсортированный массив: ";
    print(arr1, size1);
    std::cout << "\n";

    std::cout << "Исходный массив:        ";
    print(arr2, size2);
    quick_sort(arr2, size2);
    std::cout << "Отсортированный массив: ";
    print(arr2, size2);
    std::cout << "\n";

    std::cout << "Исходный массив:        ";
    print(arr3, size3);
    quick_sort(arr3, size3);
    std::cout << "Отсортированный массив: ";
    print(arr3, size3);

}

void quick_sort(int* arr, int size) {
    quick_sort_rec(arr, 0, size - 1);
}

void quick_sort_rec(int* arr, int low, int high) {
    if (low < high) {
        int pi = pivoting(arr, low, high);
  
        quick_sort_rec(arr, low, pi -1);
 
        quick_sort_rec(arr, pi + 1, high);
    }
}

int pivoting(int* arr, int low, int high) {

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            //std::swap(arr[i], arr[j]);
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //std::swap(arr[i + 1], arr[high]);
    int temp;
    temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;


}
    


void print(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1) std::cout << " ";
    }
    std::cout << "\n";
}









