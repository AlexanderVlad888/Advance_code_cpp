#include <iostream>

class CountNumbers {
private:
    int sum;    
    int count;  

public:
   
    CountNumbers () : sum(0), count(0) {}

    
    void operator()(int number) {
        if (number % 3 == 0) {
            sum += number;  
            count++;        
        }
    }

    
    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
    setlocale(LC_ALL, "");

    CountNumbers functor; 
        
    int numbers[] = { 4, 1, 3, 6, 25, 54 };
        
    for (int number : numbers) {
        functor(number);
    }
    
    std::cout << "get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "get_count() = " << functor.get_count() << std::endl;

    return 0;
}