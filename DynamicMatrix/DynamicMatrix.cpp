#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);

int main() {

    setlocale(LC_ALL, "");

    int logical_size, actual_size;

    std::cout << "Введите фактичеcкий размер массива : ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива : ";
    std::cin >> logical_size;
    try {
        if (logical_size > actual_size) throw std::out_of_range("Ошибка! Логический размер массива не может превышать фактический!");


        int* arr = new int[actual_size];
        if (arr == nullptr) throw std::bad_alloc();

        for (int i = 0; i < logical_size; ++i) {
            std::cout << "Введите arr[" << i << "] : ";
            std::cin >> arr[i];
        }
        print_dynamic_array(arr, logical_size, actual_size);


        delete[] arr;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    


}

void input() {

}


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) std::cout << arr[i];
        else std::cout << "_";
        if (i < actual_size - 1) std::cout << " ";
    }

}