#include "SSVector.h"
namespace SS {

	/*
	template<typename T>
	Vector<T>::Vector(int size, int grow) {
		
	}
	template<typename T>
	Vector<T>::~Vector() {
		delete[] vector;
	}
	*/
	/*
	template<typename T>
	Vector<T>::Vector(Vector& copyed) {
		delete[] vector;
		vector = new T[copyed.getSize()];
		vector_count = copyed.getCount;
		vector_size = copyed.getSize;
		vector_grow = copyed.getGrow();
		for (int i = 0; i < vector_count; i++) {
			vector[i] = copyed[i];
		}
	}
	template<typename T>
	Vector<T>& Vector<T>::operator+ (T adding) {
		if (vector_count + 1 <= vector_size) {
			vector[vector_count] = adding;
		}
		return *this;
	}
	*/
}
