#include <iostream>

long long fib(int n);

int main() {

	try {
		std::cout << fib(665);

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	

}

long long fib(int n) {
	if(n >= 2) {
	long long* arr = new long long[n];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];


	}

	long long  a = arr[n - 1];
	delete[] arr;
	return a;
	}
	else if (n == 1) {
		return 1;
	}
	else { throw std::invalid_argument("Quantity of elements must be greater than zero."); }
	

	
}