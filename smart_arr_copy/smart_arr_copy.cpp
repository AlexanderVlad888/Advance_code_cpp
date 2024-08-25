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


	smart_array& operator=(const smart_array& other) {
		size = other.size;
		count = other.count;
		data = (int*)calloc(size, sizeof(int));
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];

		}
		return *this;
	}

	smart_array(const smart_array& sm_arr)
	{

		//data = sm_arr.data;
		size = sm_arr.size;
		count = sm_arr.count;
		//data = new int[size];
		data = (int*)calloc(size, sizeof(int));
		for (int i = 0; i < size; i++) {
			data[i] = sm_arr.data[i];

		}

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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);



		arr = new_array;
		// smart_array new_array(arr);



		std::cout << arr.get_element(0) << std::endl;
		std::cout << new_array.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;
		std::cout << new_array.get_element(1) << std::endl;
		std::cout << arr.get_element(2) << std::endl;
		std::cout << new_array.get_element(2) << std::endl;
		std::cout << arr.get_element(3) << std::endl;
		std::cout << new_array.get_element(3) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
		std::cout << new_array.get_element(4) << std::endl;
		std::cout << arr.get_element(5) << std::endl;
		std::cout << new_array.get_element(5) << std::endl;
		std::cout << arr.get_element(6) << std::endl;
		std::cout << new_array.get_element(6) << std::endl;
		std::cout << arr.get_element(7) << std::endl;
		std::cout << new_array.get_element(7) << std::endl;




	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}

