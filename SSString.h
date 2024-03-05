#pragma once
#include <iostream>
namespace SS {
	class String
	{
		char* mass; int count_symb; int size_mass; char* buffer; 
	public:
		String();
		String(const char);
		String(const char*);
		String(const char*, int n);
		String(const String& str);
		~String();

		int getCountSymb() { return count_symb; };
		int getSize() { return size_mass; };
		char* cStyle() { return mass; };

		static char* toString(int number);
		static char* toString(short number);
		static char* toString(long long number);
		static char* toString(long number);

		static char* toString(double number);
		static char* toString(float number);

		String& operator=(const String& str);
		String& operator=(const char* str);
		String& operator=(const char c);

		String& operator+(const String& str);
		String& operator+(const char* str);
		String& operator+(const char c);

		String& operator +=(const String& str) { return *this = *this + str; };
		String& operator +=(const char* s) { return *this = *this + s; };
		String& operator +=(const char c) { return *this = *this + c; };

		friend std::ostream& operator <<(std::ostream& out, const String& str);
		void input();

		bool operator == (const String& str);
		bool operator == (const char* s);
		bool operator == (const char c);
		bool operator != (String& str) { return !(*this == str); };
		bool operator != (const char* s) { return !(*this == s); };
		bool operator != (const char c) { return !(*this == c); };
		bool operator > (String& str);
		bool operator > (const char* s);
		bool operator > (const char c);
		bool operator < (String& str);
		bool operator < (const char* s);
		bool operator < (const char c);
		bool operator >= (String& str);
		bool operator >= (const char* s);
		bool operator >= (const char c);
		bool operator <= (String& str);
		bool operator <= (const char* s);
		bool operator <= (const char c);

		char operator[] (int a);
		char at(int a);


		// finished :
		void reverseWords();

		// not finished:
		/*
			reverseWords(); reverse all string
			reverseWords(size_type pos, size_type n); reverse from this[pos] n elements
			reverseWords(size_type n); reverse first n elements
		*/

		/*
			assign(const string& str);  s1 = s2
			assign(const string& str, size_type pos, size_type n); s1 = s2(from pos index first of n) 
			assign(const char* s, size_type n); s1 = s2(first of n)

		*/
		/*
			append(const string& str ); s1 = s1 + s2;
			append(const string& str, size_type pos, size_typen); s1 = s1 + s2(from pos index first of n)
			append(const char* s, size_type n); s1 = s1 + s2(first of n)
		*/

		/*
			insert (size_type pos1, const string& str ); in s1[pos1] input s2 and then else s1
			insert (size_type pos1, const string& str, size_type pos2, size_type n); ?????
			insert (size_type pos, const char* s, size_type n); in s1[pos1] input s2 and then else s1
		*/
		/*
			erase(size_type pos = 0, size_type n = npos); delete some little string int string
			clear() delete all string;
		*/
		/*
			replace(size_type pos1,size_type n1,const string& str);  from s1[pos1] deleting n1 elements and adding to s1[pos1] str
			replace(size_type pos1, size_type n1, const string& str, size_type pos2,size_type n2); from s1[pos1] deleting n1 elements and adding to s1[pos1] str[pos2] n2 elements
			replace(size_type pos1, size_type n1, const char* s, size_type n2); from s1[pos1] deleting n1 elements and adding to s1[pos1] str
		*/
		/*
			swap(strings s); s3 = s1; s1 = s2; s2 = s3;
			string substr(size_type pos=0, size_type n=npos) const; return string n elements from this[pos]
			size_type сору(char*s,size_type n,size_type pos=0) const; copy in s n elements from this[pos]
		*/
		/*
			int compare(const string& str) const; 
			int compare(size_type pos1, size_type n1, const string& str) const;
			int compare(size_type pos1, size_type n1, const string& str, size_type pos2, size_type n2) const;
		*/
	};
}


