#pragma once
#include <string>

namespace laba3 {
	template <class T>
	class vector {
		int size = 0;
		int capacity = 0;
		T* data = 0;
	public:
		vector();
		vector(int n);
		~vector();
		vector(const vector<T>& v);
		vector<T>& operator=(const vector<T>& v);
		void resize(int newSize);
		void push_back(T k);
		T pop_back();
		void insert(int h, T k);
		T operator[](int i) const;
		T& operator[](int i);
		vector<T>& operator+=(const vector<T>& v);
		int sz() { return size; };

		template <class V>
		friend std::ostream& operator<<(std::ostream& obj, const vector<V>& v);

		template<class V>
		friend vector<V> operator+(const vector<V>& v1, const vector<V>& v2);
	};

	template<class T>
	inline vector<T>::vector() :size(0), capacity(0), data(0) {};

	template<>
	vector<std::string>::vector(int n) {
		this->data = new std::string[2 * n];
		for (int i = 0; i < n; i++) {
			this->data[i] = "0";
		}
		this->capacity = 2 * n;
		this->size = n;
	}

	template<class T>
	inline vector<T>::vector(int n) {
		this->data = new T[2 * n];
		for (int i = 0; i < n; i++) {
			this->data[i] = 0;
		}
		this->capacity = 2 * n;
		this->size = n;
	}

	template<class T>
	inline vector<T>::~vector() {
		delete[] data;
	}

	template<class T>
	inline vector<T>::vector(const vector<T>& v) {
		resize(v.size);
		for (int i = 0; i < v.size; i++) {
			this->data[i] = v.data[i];
		}
		this->size = v.size;
		this->capacity = v.capacity;
	}

	template<class T>
	inline void vector<T>::resize(int newSize) {
		int result = newSize > this->size ? this->size : newSize;
		if (newSize < this->capacity) {
			this->size = newSize;
		}
		else {
			T* data_copy = new T[2 * newSize];
			for (int i = 0; i < result; ++i) {
				data_copy[i] = this->data[i];
			}
			delete[] this->data;
			this->data = data_copy;
			this->capacity = 2 * newSize;
			this->size = newSize;
		}
	}

	template<class T>
	inline vector<T>& vector<T>::operator=(const vector<T>& v) {
		if (this == &v) {
			return *this;
		}
		delete[] this->data;
		this->capacity = v.capacity;
		this->size = v.size;
		this->data = new T[this->capacity];
		for (int i = 0; i < this->size; i++) {
			this->data[i] = v.data[i];
		}
	}

	template<class T>
	inline T vector<T>::operator[](int i) const {
		return this->data[i];
	}

	template<class T>
	inline T& vector<T>::operator[](int i) {
		return this->data[i];
	}

	template<class T>
	inline void vector<T>::push_back(T k) {
		if (this->size == this->capacity) {
			resize(this->size + 1);
			this->data[this->size - 1] = k;
			//this->capacity = this->size + 1;
			//this->size = this->size + 1;
		}
		else {
			this->size++;
			this->data[this->size - 1] = k;
		}
	}

	template<class T>
	inline T vector<T>::pop_back() {
		T tmp = this->data[this->size - 1];
		this->size--;

		return tmp;
	}

	template<class T>
	inline void laba3::vector<T>::insert(int h, T k) {
		if (this->capacity > this->size) {
			for (int i = this->size + 1; i > h; --i) {
				this->data[i] = this->data[--i];
			}
			this->data[h] = k;
			if (h >= this->size) {
				this->size++;
			}
		}
		else {
			T* data_copy = new T[this->size + 1];
			for (int i = 0; i < h; ++i) {
				data_copy[i] = this->data[i];
			}
			data_copy[h] = k;
			for (int i = h + 1; i < this->size + 1; ++i) {
				data_copy[i] = this->data[i];
			}
			delete[] this->data;
			this->data = data_copy;
			this->capacity++;
			this->size++;
		}
	}

	template<class T>
	inline vector<T>& laba3::vector<T>::operator+=(const vector<T>& v) {
		if (this->size > v.size) {
			for (int i = 0; i < v.size; i++) {
				this->data[i] += v.data[i];
			}
			for (int i = v.size; i < this->size; i++) {
				this->data[i] = this->data[i];
			}
			return *this;
		}
		else if (this->size == v.size) {
			for (int i = 0; i < v.size; i++) {
				this->data[i] += v.data[i];
			}
			return *this;
		}
		if (this->size < v.size) {
			this->resize(v.size);
			for (int i = 0; i < this->size; i++) {
				this->data[i] += v.data[i];
			}
			for (int i = this->size; i < v.size; i++) {
				this->data[i] = v.data[i];
			}
			return *this;
		}
	}

	template<class V>
	std::ostream& operator<<(std::ostream& obj, const vector<V>& v) {
		for (int i = 0; i < v.size; i++) {
			obj << "{" << v.data[i] << "}" << std::endl;
		}
		return obj;
	}

	template<class V>
	vector<V> operator+(const vector<V>& v1, const vector<V>& v2) {
		if (v1.size > v2.size) {
			vector<V> c(v1.size);
			for (int i = 0; i < v2.size; i++) {
				c.data[i] = v1.data[i] + v2.data[i];
			}
			for (int i = v2.size; i < v1.size; i++) {
				c.data[i] = v1.data[i];
			}
			return c;
		}
		else if (v1.size == v2.size) {
			vector<V> c(v1.size);
			for (int i = 0; i < v1.size; i++) {
				c.data[i] = v1.data[i] + v2.data[i];
			}
			return c;
		}
		if (v1.size < v2.size) {
			vector<V> c(v2.size);
			for (int i = 0; i < v1.size; i++) {
				c.data[i] = v1.data[i] + v2.data[i];
			}
			for (int i = v1.size; i < v2.size; i++) {
				c.data[i] = v2.data[i];
			}
			return c;
		}
	}
}