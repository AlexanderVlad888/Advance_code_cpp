#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>


template <typename Container>
void print_container(const Container& cont) {
    for (auto iterator = cont.begin(); iterator != cont.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
}

int main() { 
    
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::cout << "<set>: ";
    print_container(test_set); // four one three two. помните почему такой порядок? :)

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "<list>: ";
    print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "<vector>: ";
    print_container(test_vector); // one, two, three, four
    
    std::vector<int> vec = { 3, 2, 1, 4, 5, 9 };
    std::cout << "<vector>: ";
    print_container(vec);
        
    std::set<int> mySet = { 3, 11, -4, 2, 5 };
    std::cout << "<set>: ";
    print_container(mySet);
          
    std::list<std::string> myList = { "one", "three", "cherry", "banana", "planeta"};
    std::cout << "<list>: ";
    print_container(myList);

    std::set<std::string> mSetStr = { "one", "three", "cherry", "banana", "planeta" };
    std::cout << "<setString>: ";
    print_container(mSetStr);
        
    std::unordered_set<int> myUnSet = { 11, 31, 64, 223, 5, 223 };
    std::cout << "<unordered_set>: ";
    print_container(myUnSet);

    
   

    return 0;
}