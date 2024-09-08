#include <iostream>

int fib(int n);

int main() {
	std::cout << fib(18);

	return 0;
}

int fib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}

