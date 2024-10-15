#include <iostream>


template<typename T>
class Smart_Array {
private:
    int rows;
    int cols;
    T** data;

public:

    Smart_Array(int rows, int cols) : rows(rows), cols(cols) {
        data = new T* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols] {0};

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

    Smart_Array& operator=(const Smart_Array& other) {

        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new T* [rows];
             
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }

        }
        
        return *this;
    }

    Smart_Array(const Smart_Array& sm_arr)
    {
        rows = sm_arr.rows;
        cols = sm_arr.cols;
        data = new T* [rows];
        
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = sm_arr.data[i][j];

            }
        }

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

    Smart_Array<int> t1(2, 3);
    Smart_Array<int> t2(2, 3);
    t2[0][1] = 9;
    t1 = t2;
    t2[0][0] = 7;
    t1.print();
    


    Smart_Array<double> t5(2, 3);
    t5[1][0] = 4;
    Smart_Array<double> t6(t5);
    t5[1][2] = 7;
    t6.print();
    t5.print();


}