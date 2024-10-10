#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

namespace oopstd {

	class string {
	public:
		string();
		string(const char* s);
		string(const string& str);
		~string();

		string& assign(const string& str);
		char& at(size_t pos);
		const char* c_str()const;
		void clear();
		void push_back(char c);
		int compare(const string* str) const;
		string& replace(size_t pose, size_t len, const string* str);
		string substr(size_t pos, size_t len) const;
		size_t find(const string& str, size_t pos) const;

	private:
		char* s; //문자열
		size_t len; //문자열의 길이
	};

	int stoi(const string& str, size_t* idx, int base);
	float stof(const string& str, size_t* idx);

	string to_string(int val);
	string to_string(float val);
}