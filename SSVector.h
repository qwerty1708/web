#pragma once
#include "SSString.h"
#include "fun_console.h"
#include <iostream>
namespace SS {
	template<class T>
	class Vector
	{
		T* vector; int vector_size; int vector_count; int vector_grow;
	public:                                                                
		Vector(int size = 0, int grow = 0) {
			if (grow < 1) grow = 1;
			if (size < 1) size = 0;
			vector_size = size;
			vector_grow = grow;
			vector = new T[vector_size + vector_grow ];
			vector_size = vector_size + vector_grow;
			vector_count = 0;
		}
		Vector(Vector& copyed) {
			*this = copyed;
		}

		int getSize() { return vector_size;  };
		int getCount() { return vector_count; };
		int getGrow() { return vector_grow; };

		Vector& operator+ (T adding) {
			if (vector_count + 1 <= vector_size) {
				vector[vector_count++] = adding;
			}
			else {
				Vector<T> buff = *this;
				for (int i = 0; i < vector_size;i++) {
					buff[i] = vector[i];
				}
				delete[] vector;
				vector = new T[vector_size + vector_grow];
				for (int i = 0; i < vector_size;i++) {
					vector[i] = buff[i];
				}
				vector[vector_count++] = adding;
				vector_size += vector_grow;
			}
			return *this;
		}
		Vector& operator+ (Vector& copyed) {
			if (vector_count + copyed.getCount() <= vector_size) {
				for (int i = 0; i < copyed.getCount(); i++) {
					vector[vector_count++] = copyed[i];
				}
			}
			else {
				Vector<T> buff = *this;
				delete[] vector;
				vector = new T[vector_count + copyed.getCount()];
				vector_size = vector_count + copyed.getCount();
				for (int k = 0; k < vector_count; k++) {
					vector[k] = buff[k];
				}
				for (int i = 0; i < copyed.getCount(); i++) {
					vector[vector_count++] = copyed[i];
				}
			}
			return *this;
		}

		void operator = (Vector& copyed) {
			delete[] vector;
			vector_size = copyed.getSize();
			vector_count = copyed.getCount();
			vector_grow = copyed.getGrow();
			vector = new T[vector_size];
			for (int i = 0; i < vector_count; i++) {
				vector[i] = copyed[i];
			}
		}

		T myfunc() {
			T dobutok = 1.0;
			bool is = false;
			for (int i = 1; i < vector_size;i = i + 2) {
				
				if (int(vector[i]) % 2 != 0) {
					is = true;  
					dobutok *= int(vector[i]);
				}
			}
			if (is == false) dobutok = 0;
			return dobutok;
		} 

		T& operator[] (int place) { return *(vector + place); };

		bool at(int place) {
			if (place > 0 && place<= vector_count) return true;
			else return false;
		}

		void cout(int x = 0 ,int y = 0) {
			for (int i = 0; i < vector_count; i++) {
				GotoXY(x, y + i);
				std::cout << vector[i] << std::endl;
			}
		}

		~Vector() {
			delete[] vector;
		};
	};
}


