#include <vcruntime.h>

template<class T>
class queue {
private:
	size_t start;
	size_t end;
	size_t size_of_queue;
	size_t size_of_data;
	T* data;
public:
	queue(): start(0), end(0), size_of_queue(0){
		data = new T[5];
		size_of_data = 5;
	};

	queue(T val): start(0), end(1) {
		data = new T[5];
		data[0] = val;
		size_of_data = 5;
		size_of_queue = 1;
	};

	~queue() {
		delete[] data;
	};

	void push(T val) {
		if ((size_of_queue == size_of_data) && (start % size_of_data == end % size_of_data)) {
			resize_();
			data[end % size_of_data] = val;
			end++;
			size_of_queue++;
		}
		else if (start % size_of_data > end % size_of_data) {
			data[end % size_of_data] = val;
			end++;
			size_of_queue++;
		}
		else if (size_of_queue == 0) {
			end = 0;
			start = 0;
			data[end % size_of_data] = val;
			end++;
			size_of_queue++;
		}
		else {
			data[end % size_of_data] = val;
			end++;
			size_of_queue++;
		}

	};

	void pop() {
		if (size_of_queue == 0)
			throw std::out_of_range("Trying pop empty stack");
		else {
			data[start % size_of_data] = NULL;
			size_of_queue--;
			start++;
		}
	};

	T front() {
		if (size_of_queue != 0)
			return data[start % size_of_data];
		throw std::out_of_range("Empty queue");
	};

	bool empty() {
		return (size_of_queue == 0);

	};

	size_t sz_of_q() { return size_of_queue; };

	size_t sz_of_d() { return size_of_data; };

	void resize_() {
		T* datacopy = new T[2 * size_of_data];
		for (int i = 0; i < size_of_queue; i++) {
			datacopy[i] = data[start % size_of_data];
			start++;
		}
		delete[] data;
		data = datacopy;
		start = 0;
		end = size_of_queue;
		size_of_data *= 2;
	};
};