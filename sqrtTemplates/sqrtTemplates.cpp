#include <iostream>
#include <vector>

template<class T> T my_sqrt(T a);
template<class T> std::vector<T> my_sqrt(std::vector<T>& vec);
  

int main()
{

    int a = 5;
    float b = 7.8;

   std::cout << my_sqrt(a) << " " << my_sqrt(b) << "\n";

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
    

    for (int n : vec) {
        std::cout << n << " ";
    }

    std::cout << "\n";

    std::vector<int> vec2 = my_sqrt(vec);

   
    for (int n : vec2) {
        std::cout << n << " ";

    }

}


  template<class T>
  std::vector<T> my_sqrt(std::vector<T>& vec) {
      std::vector<T> vec_new(vec.size());
      for (int i = 0; i < vec.size(); ++i) {
          vec_new[i] = my_sqrt(vec[i]);

      }
      return vec_new;
  }
  
  template<class T>
    T my_sqrt(T a) {
       return a * a;
       
    }
