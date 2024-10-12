#include <iostream>


template<typename T>
class Smart_Array {
public:
    int rows;
    int cols;
    int** data;

    Smart_Array(int rows, int cols) : rows(rows), cols(cols) {
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols] {0};

        }

    }

    ~Smart_Array() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        printf("Array deleted\n");
    }

    T* operator[](int index) {

        return data[index];
    }

    const T* operator[](int index) const {
        return data[index];
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j];
                if (j < cols - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    void Size() const {
        std::cout << "Size: " << rows << " x " << cols << std::endl;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    auto arr = Smart_Array<int> (2, 4);
    arr[1][1] = 5;
    arr[0][1] = 3;
    std::cout << arr[1][1] * arr[0][1] << std::endl;
    arr.print();
    arr.Size();


}