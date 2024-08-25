#include <iostream>


class smart_array
{
private:
	int* data;
	int size;
	int count;
public:
	smart_array(int init_size) {
		if (init_size == 0) {
			throw std::invalid_argument("Quantity of elements must be greater than zero.");
		}
		size = init_size;
		//data = new int[size];
		data = (int*)calloc(size, sizeof(int));
		if (data == nullptr) {
			throw std::bad_alloc();
		}
		count = 0;

	}

	~smart_array() {
		//delete [] data;
		free(data);
		printf("Array deleted\n");

	}

	void add_element(int element) {
		if (count >= size) {
			size++;
			int* ptr = (int*)realloc(data, size * sizeof(int));
			if (ptr != nullptr) {
				data = ptr;
			}
			else {
				throw std::bad_alloc();
			}
		}
		data[count] = element;
		count++;
	}

	int get_element(int index) {
		if (index >= count) {
			throw std::out_of_range("Index is out of range.");
		}
		return data[index];
	}
};






int main() {
	try {
		smart_array arr(1);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(78);
		arr.add_element(7);
		arr.add_element(92);

		std::cout << arr.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.get_element(2) << std::endl;
		std::cout << arr.get_element(3) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
		std::cout << arr.get_element(5) << std::endl;
		std::cout << arr.get_element(6) << std::endl;
		std::cout << arr.get_element(7) << std::endl;




	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}

