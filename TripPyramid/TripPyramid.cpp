#include <iostream>

void printMatrix(const int* arr, int size);
void printPyramid(const int* arr, int size);
int intLog(int value);
int getIndexTree(int size, int current_index, std::string ans);
void printElemPyramid(const int* arr, int current_index);
std::string input();

int main()
{
    setlocale(LC_ALL, "");
    std::string ans;
    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(arr) / sizeof(int);
    
    printPyramid(arr, size);
    std::cout << "\n";

    int current_index = 0;
    printElemPyramid(arr, 0);

    do {
        ans = input();
            if (ans == "exit") {
                
            }
            else if (getIndexTree(size, current_index, ans) >= 0) {
                current_index = getIndexTree(size, current_index, ans);
                std::cout << "Ok\n";
                printElemPyramid(arr, current_index);
            }
            else if (getIndexTree(size, current_index, ans) == -3) {
                std::cout << "Ошибка! Отсутствует родитель\n";
                printElemPyramid(arr, current_index);

            }
            else if (getIndexTree(size, current_index, ans) == -1) {
                std::cout << "Ошибка! Отсутствует левый потомок\n";
                printElemPyramid(arr, current_index);

            }
            else if (getIndexTree(size, current_index, ans) == -2) {
                std::cout << "Ошибка! Отсутствует правый потомок\n";
                printElemPyramid(arr, current_index);
            }
    } while (ans != "exit");
    
    
   

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

int getIndexTree(int size, int current_index, std::string ans) {
    int new_index;
    if (ans == "up") {
        new_index = (current_index % 2 == 0) ? (current_index / 2) - 1 : current_index / 2;
        if (new_index < 0) new_index = -3;
    }
    else if (ans == "left") {
        new_index = (current_index * 2) + 1;
        if (new_index  >= size ) new_index = -1;
    }
    else if (ans == "right") {
        new_index = (current_index * 2) + 2; 
        if (new_index  >= size ) new_index = -2;
    }

    

    return new_index;
}

void printElemPyramid(const int* arr, int current_index) {
   
    std::cout << "Вы находитесь здесь: ";
   
        if (current_index == 0) {
            std::cout << intLog(current_index + 1) << " root " << arr[current_index] << "\n";
        }
        else if (current_index % 2 != 0) {
            std::cout << intLog(current_index + 1) << " left(" << arr[current_index / 2] << ") " << arr[current_index] << "\n";
        }
        else {
            std::cout << intLog(current_index + 1) << " right(" << arr[current_index / 2 - 1] << ") " << arr[current_index] << "\n";
        }
    
}

std::string input(){
    std::cout << "Введите команду: ";
    std::string ans;
    std::cin >> ans;
     return ans;
}
