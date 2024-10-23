#include <iostream> 
#include <unordered_map> 
#include <vector> 
#include <algorithm>
#include <string>

int main()
{   
    setlocale(LC_ALL, "");

    std::unordered_map<char, unsigned> products;
        
    std::string input; 
    std::cout << "Введите текст: "; 
    std::getline(std::cin, input); 
 
    for (char ch : input) { 
        products[ch]++; 
    }

    std::vector<std::pair<char, unsigned>> freqVector(products.begin(), products.end());

    std::sort(freqVector.begin(), freqVector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; 
     });

    for (const auto& elem : freqVector)
        std::cout << elem.first << ": " << elem.second << std::endl;

}

