#include <iostream>



template<typename T>
class Vector {
private:
    T* data;            
    int currentSize;    
    int currentCapacity; 

public:
    
    Vector() : currentSize(0), currentCapacity(2) {
        data = new T[currentCapacity]; 
        if (data == nullptr) {
            throw std::bad_alloc();
        }
    }

    
    ~Vector() {
        delete[] data; 
    }

    
    T& at(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    
    void push_back(T value) {
        
        if (currentSize == currentCapacity) {
            
            int newCapacity = currentCapacity * 2;
            T* newData = new T[newCapacity];

            
            for (int i = 0; i < currentSize; i++) {
                newData[i] = data[i];
            }

            delete[] data; 
            data = newData; 
            currentCapacity = newCapacity; 
        }

        
        data[currentSize] = value;
        currentSize++;
    }

    
    int size() const {
        return currentSize; 
    }

    
    int capacity() const {
        return currentCapacity;
    }
    Vector& operator=(const Vector& other) {

        if (this == &other) {
            return *this;
        }
        delete[] data;
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new T[currentCapacity];
        if (data == nullptr) {
            throw std::bad_alloc();
        }
        for (int i = 0; i < currentSize; i++) {
            this->data[i] = other.data[i];

        }
        return *this;
    }

    Vector(const Vector& sm_arr)
    {
        currentSize = sm_arr.currentSize;
        currentCapacity = sm_arr.currentCapacity;
        data = new T[currentCapacity];
        if (data == nullptr) {
            throw std::bad_alloc();
        }
        for (int i = 0; i < currentSize; i++) {
            data[i] = sm_arr.data[i];

        }

    }

    T& operator[](int index) {

        return at(index);
    }

    const T& operator[](int index) const {
        return at(index);
    }

    void print() {
        for (int i = 0; i < currentSize; ++i) {

            std::cout << data[i];
            if (i < currentSize - 1) std::cout << " ";


        }
        std::cout << "\n";
    }


};

int main() {

    try
    {
        Vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(7);
        vec.push_back(9);
        vec.push_back(12);

        std::cout <<  vec.size() << '\n'; 
        std::cout <<  vec.capacity() << '\n'; 
               
        Vector<int> vec2 = vec;

        vec.push_back(-8);

        Vector<int> vec3(vec);

        vec.print();
        vec2[5] = 45;
        vec2.print();
        vec3.push_back(74);
        vec3.push_back(543);
        vec3.push_back(89);
        vec3.print();
        Vector<int> vec4(vec);
        vec4.print();

        vec[8] = 504;


    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}