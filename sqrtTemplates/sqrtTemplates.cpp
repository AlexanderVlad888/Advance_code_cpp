#include <iostream>
#include <vector>

template<class T> T my_sqrt(T a);
template<class T> void my_sqrt(std::vector<T>& vec);
  



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

    my_sqrt(vec);

    for (int n : vec) {
        std::cout << n << " ";

    }
   

}


  template<class T>
  void my_sqrt(std::vector<T>& vec) {
      for (int i = 0; i < vec.size(); ++i) {
          vec[i] = my_sqrt(vec[i]);

      }
    }
  
  template<class T>
    T my_sqrt(T a) {
       return a * a;
       
    }
