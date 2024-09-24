#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void input(int* logical_size, int* actual_size);
void remove_dynamic_array_head(int*& arr, int* logical_size, int* actual_size);
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
        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
        remove_dynamic_array_head(arr, &logical_size, &actual_size);

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

void remove_dynamic_array_head(int*& arr, int* logical_size, int* actual_size) {

    bool end = false;
    while (!end) {
        std::cout << "Удалить первый элемент? ";
        std::string answer;
        std::cin >> answer;


        if (answer == "да" || answer == "Да" ||  answer == "Yes" || answer == "yes") {
            
            if (*logical_size == 0) {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
                end = true;

            }
            else if (*logical_size - 1 > *actual_size / 3 || (*logical_size == 1 && *actual_size == 1)) {

                for (int i = 0; i < *logical_size - 1; ++i) {
                    arr[i] = arr[i + 1];
                }
                (*logical_size)--;
                std::cout << "Динамический массив: ";
                print_dynamic_array(arr, *logical_size, *actual_size);
                


            }
            else if ((*logical_size) - 1 <= (*actual_size) / 3) { 
                (*actual_size) /= 3;
                int* arr2 = new int[(*actual_size)];
                if (arr2 == nullptr) throw std::bad_alloc();
                for (int i = 0; i < *logical_size - 1; ++i) {
                    arr2[i] = arr[i + 1];
                }
                delete[] arr;
                arr = arr2;
                (*logical_size)--;
                std::cout << "Динамический массив: ";
                print_dynamic_array(arr, *logical_size, *actual_size);
               
                


            }
            
            
        } else if (answer == "нет" || answer == "Нет" ||  answer == "No" || answer == "no") {
            end = true;
        }
        else {
            std::cout << "Введите корректный ответ \"да\" или \"нет\"\n";
        }


        
        

    }
    
       // std::cout << "Спасибо!Ваш динамический массив: ";
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


