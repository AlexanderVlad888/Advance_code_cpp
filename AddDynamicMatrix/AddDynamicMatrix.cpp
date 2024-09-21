#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void input(int* logical_size, int* actual_size);
void addElement(int* arr, int* logical_size, int* actual_size);
void fillMatrix(int* arr, int logical_size, int actual_size);

int main() {

    setlocale(LC_ALL, "");
    int logical_size, actual_size;
    input(&logical_size, &actual_size);
    int* arr = new int[actual_size];
    if (arr == nullptr) throw std::bad_alloc();
    try {
        if (logical_size > actual_size) throw std::out_of_range("Ошибка! Логический размер массива не может превышать фактический!");

        fillMatrix(arr, logical_size, actual_size);
        std::cout << "Динамический массив ";
        print_dynamic_array(arr, logical_size, actual_size);
        addElement(arr, &logical_size, &actual_size);

        delete[] arr;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    

   

}

void input(int* logical_size, int* actual_size) {
    
    std::cout << "Введите фактичеcкий размер массива : ";
    std::cin >> *actual_size;
    std::cout << "Введите логический размер массива : ";
    std::cin >> *logical_size;
    
}

void addElement(int* arr, int* logical_size, int* actual_size) {
    
   
    while (true) {
        std::cout << "Введите элемент для добавления: "; 
        int elem;
        std::cin >> elem;
    
        if (elem == 0) {
            
            break; 
        }

    
        if (*logical_size == *actual_size) {
            (*actual_size) *= 2;
            int* arr2 = new int[(*actual_size)];
            if (arr2 == nullptr) throw std::bad_alloc();
            for (int i = 0; i < *logical_size; ++i) {
                arr2[i] = arr[i];
            }
            //delete[] arr;
            arr = arr2;
        }
        arr[(*logical_size)] = elem;
        (*logical_size)++;
        std::cout << "Динамический массив ";
        print_dynamic_array(arr, *logical_size, *actual_size);
        
    

    }
    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, *logical_size, *actual_size);
    

}

void fillMatrix(int* arr, int logical_size, int actual_size) { 
    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "] : ";
        std::cin >> arr[i];
        }

}


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) std::cout << arr[i];
        else std::cout << "_";
        if (i < actual_size - 1) std::cout << " ";
    }
    std::cout << "\n";

}
