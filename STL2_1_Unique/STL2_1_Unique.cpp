#include <iostream>
#include <vector>
#include <algorithm>


template <typename Container>
void print_container(const Container& cont) {
    for (auto iterator = cont.begin(); iterator != cont.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
}

int main() {
    
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
    print_container(vec);
    std::sort(vec.begin(), vec.end(), std::greater<>());
    print_container(vec);
    std::sort(begin(vec), end(vec));
    print_container(vec);

    auto it2 = std::unique(vec.begin(), vec.end());
    vec.erase(it2, vec.end()); 
    print_container(vec);

   
    return 0;
}