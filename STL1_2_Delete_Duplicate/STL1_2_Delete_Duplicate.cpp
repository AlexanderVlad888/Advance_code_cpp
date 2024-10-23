#include <iostream> 
#include <string> 
#include <set> 
#include <algorithm> 
#include <vector> 

int main()
{
    std::string b;
    std::cin >> b;
    int a = std::stoi(b);
    std::set<int> products;

    for (int i = 0; i < a; ++i) {
        std::cin >> b;
        int a = std::stoi(b);
        products.insert(a);
    }

    std::vector<int> sortedProducts(products.begin(), products.end());

    std::sort(sortedProducts.begin(), sortedProducts.end(), std::greater<int>());

    std::cout << "OUT:\n";
    for (const auto& elem : sortedProducts) {
        std::cout << elem << std::endl; 
    }


}
//STL1_2