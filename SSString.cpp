#include "SSString.h"
#include <iostream>
#include <conio.h>
namespace SS {
	String::~String() {
		delete[] mass;
		//delete[] buffer;
	}
	char String::operator[] (int a){
		return *(mass + a);
	}
	char String::at(int a) {
		if (a > 0 && a <= count_symb) {
			return mass[a - 1];
		}
		else return NULL;
	}
	std::ostream& operator <<(std::ostream& out, const String& str) {
		out << str.mass;
		return out;
	}
	void String::input() {
		char input = '0';
		while (input != 13) {
			input = _getch();
			if (input != 13) {
				std::cout << input; *this += input;
			}
			if (input == 8) { std::cout << ' '; std::cout << input; }
		}
	}
	//&& ((buffer[i + 1] >= 65 && buffer[i + 1] <= 90) || (buffer[i + 1] >= 97 && buffer[i + 1] <= 122))
	void String::reverseWords() {
		buffer = new char[size_mass + 1];
		int i = 0; 
		while (mass[i] != NULL) {
			buffer[i] = mass[i];
			i++;
		}
		buffer[i] = NULL;

		int k = 0;
		while (buffer[i] != ' ' && i > -1) {
			i--;
		}
		int n = i +1;
		bool was = false;
		char charwas;
		if (buffer[0] >= 65 && buffer[0] <= 90) buffer[0] += 32;
		while (buffer[n] != NULL) {
			if (buffer[n] == '!' || buffer[n] == '.' || buffer[n] == '?') { was = true; mass[k] = ' '; charwas = buffer[n]; n++;  break; };
			mass[k] = buffer[n];
			k++; n++;
		}

		if(mass[0] >= 97 && mass[0] <= 122) mass[0] -= 32;
		mass[k] = ' ';
		k++;
		i--;
		while (i > -1) {
			while (buffer[i] != ' ' && i > -1) {
				i--;
			}
			n = i + 1;
			while (buffer[n] != ' ') {
				mass[k] = buffer[n];
				k++; n++;
			}
			mass[k] = ' ';
			k++;
			i--;
		}
		if (was == true) { mass[k - 1] = charwas; };
		mass[count_symb] = NULL;
	}
	String::String() {
		count_symb = 0;
		size_mass = 0;
		mass = new char[1];
		mass[0] = NULL;
		buffer = NULL;
	}
	String::String(const char c) {
		count_symb = 1;
		size_mass = 1;
		mass = new char[2];
		mass[0] = c;
		mass[1] = NULL;
		buffer = NULL;
	}
	String::String(const char* str) {
		int i = 0;
		while (str[i] != NULL) {
			i++;
		}
		count_symb = i;
		size_mass = i;
		mass = new char[size_mass + 1];
		i = 0;
		while (str[i] != NULL) {
			mass[i] = str[i];
			i++;
		}
		mass[size_mass] = NULL;
		buffer = NULL;
	}
	String::String(const char* str, int n) {
		int i = 0;
		while (str[i] != NULL) {
			i++;
		}
		if (i > n) {
			count_symb = n;
			size_mass = n;
			mass = new char[size_mass + 1];
			i = 0;
			while (str[i] != NULL && count_symb > i) {
				mass[i] = str[i];
				i++;
			}
			mass[count_symb] = NULL;
		}
		else {
			size_mass = n;
			count_symb = i;
			mass = new char[size_mass + 1];
			i = 0;
			while (str[i] != NULL) {
				mass[i] = str[i];
				i++;
			}
			mass[count_symb] = NULL;
		}
		buffer = NULL;
	}
	String::String(const String& str) {
		this->count_symb = str.count_symb;
		this->size_mass = str.size_mass;
		this->mass = new char[this->size_mass + 1];
		int i = 0;
		while (str.mass[i] != NULL) {
			this->mass[i] = str.mass[i];
			i++;
		}
		this->mass[this->count_symb] = NULL;
		buffer = NULL;
	}
	String& String::operator =(const char c) {
		delete[]mass;
		count_symb = 1;
		size_mass = 1;
		mass = new char[2];
		mass[0] = c;
		mass[1] = NULL;
		return *this;
	}
	String& String::operator=(const char* str) {
		delete[]mass;
		int i = 0;
		while (str[i] != NULL) {
			i++;
		}
		count_symb = i;
		size_mass = i;
		mass = new char[size_mass + 1];
		i = 0;
		while (str[i] != NULL) {
			mass[i] = str[i];
			i++;
		}
		mass[size_mass] = NULL;
		return *this;
	}
	String& String::operator=(const String& str) {
		buffer = new char[str.size_mass + 1];
		int i = 0;
		while (str.mass[i] != NULL) {
			buffer[i] = str.mass[i];
			i++;
		}
		buffer[i] = NULL;
		delete[] mass;
		mass = new char[str.size_mass + 1];
		i = 0;
		while (buffer[i] != NULL) {
			mass[i] = buffer[i];
			i++;
		}
		mass[i] = NULL;
		count_symb = str.count_symb;
		size_mass = str.size_mass;
		delete[]buffer;
		return *this;
	}
	
	String& String::operator+(const char c) {
		if (count_symb + 1 <= size_mass) {
			mass[count_symb] = c;
			mass[count_symb + 1] = NULL;
			count_symb++;
		}
		else {
			size_mass++;
			count_symb = size_mass;
			buffer = new char[size_mass + 1];
			int i = 0;
			while (mass[i] != NULL) {
				buffer[i] = mass[i];
				i++;
			}
			buffer[size_mass - 1] = c;
			buffer[size_mass] = NULL;
			delete[] mass;

			mass = new char[size_mass + 1];
			i = 0;
			while (buffer[i] != NULL) {
				mass[i] = buffer[i];
				i++;
			}
			mass[size_mass] = NULL;
			delete[]buffer;
		}
		return *this;
	}
	String& String::operator+(const char* str) {
		int i = 0;
		while (str[i] != NULL) {
			i++;
		}
		if (count_symb + i <= size_mass) {
			int k = 0;
			i = count_symb;
			while (str[k] != NULL) {
				mass[i] = str[k];
				i++; k++;
			}
			mass[i] = NULL;
			count_symb += i;
		}
		else {
			buffer = new char[size_mass + 1];
			int k = 0;
			while (mass[k] != NULL) {
				buffer[k] = mass[k];
				k++;
			}
			buffer[k] = NULL;
			delete[] mass;

			mass = new char[count_symb + i + 1];
			k = 0;
			while (buffer[k] != NULL) {
				mass[k] = buffer[k];
				k++;
			}
			i = 0;
			while (str[i] != NULL) {
				mass[k] = str[i];
				k++; i++;
			}
			mass[k] = NULL;
			count_symb = k;
			size_mass  = k;
			delete[] buffer;
		}
		return *this;
	}
	String& String::operator+(const String& str) {
		if (count_symb + str.count_symb <= size_mass) {
			int k = 0;
			while (str.mass[k] != NULL) {
				mass[count_symb] = str.mass[k];
				count_symb++; k++;
			}
			mass[count_symb] = NULL;
		}
		else {
			buffer = new char[size_mass + 1];
			int i = 0;
			while (mass[i] != NULL) {
				buffer[i] = mass[i];
				i++;
			}
			buffer[i] = NULL;
			delete[] mass;

			mass = new char[count_symb + str.count_symb + 1];
			i = 0;
			while (buffer[i] != NULL) {
				mass[i] = buffer[i];
				i++;
			}
			int k = 0;
			while (str.mass[k] != NULL) {
				mass[i] = str.mass[k];
				i++; k++;
			}
			mass[i] = NULL;
			size_mass = count_symb + str.count_symb;
			count_symb = size_mass;
			delete[] buffer;
		}
		return *this;
	}
	bool String::operator == (const char c) {
		if (mass[0] = c && (count_symb == 1)) return true;
		else return false;
	}
	bool String::operator == (const char* s) {
		int i = 0;
		while (s[i] != NULL) {
			i++;
		}
		if (i == count_symb) {
			bool rivno = true;
			i = 0;
			while (s[i] != NULL) {
				if (s[i] != mass[i]) { rivno = false; break; }
				i++;
			}
			return rivno;
		}
		else {
			return false;
		}
	}
	bool String::operator == (const String& str) {
		if (count_symb == str.count_symb) {
			int i = 0;
			bool rivno = true;
			while (str.mass[i] != NULL) {
				if (mass[i] != str.mass[i]) { rivno = false; break; }
				i++;
			}
			return rivno;
		}
		else {
			return false;
		}
	}

	char* String::toString(int number) {
		char* stat;
		if (number == 0) {
			stat = new char[2];
			stat[0] = '0';
			stat[1] = NULL;
			return stat;
		}
		int copy = number;
		int i = 0;
		if (number < 0) { i++; copy = -copy; };
		while (copy / 10 != 0) {
			i++;
			copy = copy / 10;
		}
		i++;
		stat = new char[i + 1];
		copy = number;
		if (number < 0) copy = -number;
		int k = i - 1;
		while (k >= 0) {
			stat[k] = '0' + (copy % 10);
			copy = copy / 10;
			k--;
		}
		if (number < 0) stat[0] = '-';
		stat[i] = NULL;
		return stat;
	}

	char* String::toString(short number) {
		char* stat;
		if (number == 0) {
			stat = new char[2];
			stat[0] = '0';
			stat[1] = NULL;
			return stat;
		}
		short copy = number;
		int i = 0;
		if (number < 0) { i++; copy = -copy; };
		while (copy / 10 != 0) {
			i++;
			copy = copy / 10;
		}
		i++;
		stat = new char[i + 1];
		copy = number;
		if (number < 0) copy = -number;
		int k = i - 1;
		while (k >= 0) {
			stat[k] = '0' + (copy % 10);
			copy = copy / 10;
			k--;
		}
		if (number < 0) stat[0] = '-';
		stat[i] = NULL;
		return stat;
	}
	char* String::toString(long number) {
		char* stat;
		if (number == 0) {
			stat = new char[2];
			stat[0] = '0';
			stat[1] = NULL;
			return stat;
		}
		long copy = number;
		int i = 0;
		if (number < 0) { i++; copy = -copy; };
		while (copy / 10 != 0) {
			i++;
			copy = copy / 10;
		}
		i++;
		stat = new char[i + 1];
		copy = number;
		if (number < 0) copy = -number;
		int k = i - 1;
		while (k >= 0) {
			stat[k] = '0' + (copy % 10);
			copy = copy / 10;
			k--;
		}
		if (number < 0) stat[0] = '-';
		stat[i] = NULL;
		return stat;
	}
	char* String::toString(long long number) {
		char* stat;
		if (number == 0) {
			stat = new char[2];
			stat[0] = '0';
			stat[1] = NULL;
			return stat;
		}
		long long copy = number;
		int i = 0;
		if (number < 0) { i++; copy = -copy; };
		while (copy / 10 != 0) {
			i++;
			copy = copy / 10;
		}
		i++;
		stat = new char[i + 1];
		copy = number;
		if (number < 0) copy = -number;
		int k = i - 1;
		while (k >= 0) {
			stat[k] = '0' + (copy % 10);
			copy = copy / 10;
			k--;
		}
		if (number < 0) stat[0] = '-';
		stat[i] = NULL;
		return stat;
	}
	char* String::toString(float number) {
		char* stat;
		if (number ==  0) {
			stat = new char[2];
			stat[0] = '0';
			stat[1] = NULL;
			return stat;
		}
		double copy = number;
		int i = 0;
		if (number < 0) {i++; copy = -copy;}
		if (number < 0) { copy = -number; }
		while (copy / 10 > 1) {
			i++;
			copy = copy / 10;
		}
		i++;
		stat = new char[i + 1 + 3];
		
		copy = number;
		if (number < 0) copy = -number;
		int k = i - 1;
		while (k >= 0) {
			stat[k] = '0' + (int(copy) % 10);
			copy = copy / 10;
			k--;
		}
		if (number < 0) stat[0] = '-';
		copy = number;
		if (number < 0) copy = -number;
		double drob = copy - int(copy);
		stat[i] = '.';
		stat[i + 1] = '0' + int(drob *= 10);
		stat[i + 2] = '0' + int(drob *= 10)%10;
		stat[i + 3] = NULL;
		return stat;
	}
	char* String::toString(double number) {
		char* stat;
		if (number == 0) {
			stat = new char[2];
			stat[0] = '0';
			stat[1] = NULL;
			return stat;
		}
		double copy = number;
		int i = 0;
		if (number < 0) { i++; copy = -copy; }
		if (number < 0) { copy = -number; }
		while (copy / 10 > 1) {
			i++;
			copy = copy / 10;
		}
		i++;
		stat = new char[i + 1 + 3];

		copy = number;
		if (number < 0) copy = -number;
		int k = i - 1;
		while (k >= 0) {
			stat[k] = '0' + (int(copy) % 10);
			copy = copy / 10;
			k--;
		}
		if (number < 0) stat[0] = '-';
		copy = number;
		if (number < 0) copy = -number;
		double drob = copy - int(copy);
		stat[i] = '.';
		stat[i + 1] = '0' + int(drob *= 10);
		stat[i + 2] = '0' + int(drob *= 10) % 10;
		stat[i + 3] = NULL;
		return stat;
	}
}