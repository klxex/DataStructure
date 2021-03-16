#pragma once

template<typename T>
class Vector {
private:
	T* arr;
	int size, len;
public:
	Vector() {
		size = 0; len = 4;
		arr = new T[len];

	}
	int size() {
		return size;
	}

	bool empty() {
		return size == 0;
	}
	bool full() {
		return size == len;
	}

	void push_back(T data) {
		if (full()) {
			len = len * 2;
			T* temp = new T[len];
			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = tmp;
		}
		arr[size] = data;
		size++;

	}
	T get(int idx) {
		return arr[idx];
	}
	void clear() {
		delete[] arr;
		size = 0; len = 4;
		arr = new len[len];
	}

};