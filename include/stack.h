#pragma once
#include "vector.h"

template <class T>
class stack {
private:
	laba3::vector<T> data;
	size_t size;
public:
	stack(): data(0), size(0) {};

	stack(T val):data(1), size(1) {
		data[0] = val;
	};

	size_t sz() { return size; };

	void push(T val) {
		size++;
		data.push_back(val);

	};

	void pop() {
		if (size == 0)
			throw std::exception("Empty stack doesn't have elements");
		size--;
		data.pop_back();
	};

	T top() {
		if (size == 0)
			throw std::exception("Empty stack doesn't have elements");
		return data[size - 1];
	};

	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	};

};