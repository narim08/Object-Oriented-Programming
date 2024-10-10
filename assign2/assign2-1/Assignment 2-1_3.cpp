#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "oopstd.h" //기존 헤더파일의 함수와 비교할시 이 부분 주석처리
using namespace std;

struct MEMcpy{ //memcpy에서 쓰일 구조체
	char name[40];
	int age;
}person;


int main()
{
	cout << "/* memset */" << endl;
	char str[30] = "Hello world";
	cout << str << endl;
	memset(str, '-', 5);
	cout << "memset: " << str << endl << endl;


	cout << "/* memcpy */" << endl;
	char Name[] = "abc";
	memcpy(person.name, Name, strlen(Name) + 1); //이름 복붙
	int Age = 21;
	memcpy(&person.age, &Age, 1); //나이 복붙
	cout << "memcpy: " << person.name << ", " << person.age << endl;
	cout << endl;


	cout << "/* strcmp */" << endl;
	char str1[30] = "abcde";
	char str2[30]="abcd!";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	if (strcmp(str1, str2)==0) { //문자열 비교
		cout << "동일한 문자열입니다." << endl;
	}
	else {
		cout << "서로 다른 문자열입니다." << endl;
	}
	cout << endl;


	cout << "/* strncmp */" << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "비교 길이: 3" << endl;
	if (strncmp(str1, str2, 3)==0) { //문자열 비교
		cout << "동일한 문자열입니다." << endl;
	}
	else {
		cout << "서로 다른 문자열입니다." << endl;
	}
	cout << endl;


	cout << "/* strcpy */" << endl;
	char dest[30] = {};
	char sour[30] = "strcpy test";
	strcpy(dest, sour); //문자열 복사
	cout << "str: " << sour << endl;
	cout << "strcpy: " << dest << endl;
	cout << endl;

	cout << "/* strncpy */" << endl;
	char dest2[30] = {};
	char sour2[30] = "strncpy test";
	strncpy(dest2, sour2, 3);
	cout << "str: " << sour2 << endl;
	cout << "복사 길이: 3"<< endl;
	cout << "strncpy: " << dest2 << endl;
	cout << endl;


	cout << "/* atoi */" << endl;
	char nstr[10] = "100";
	cout << "str: " << nstr << endl;
	cout<< "atoi/2: " << atoi(nstr) / 2 << endl;
	cout << endl;

	cout << "/* atof */" << endl;
	char fstr[20] = "5";
	cout << "str: " << fstr << endl;
	printf("atof: %f", atof(fstr));
	cout << endl;

	return 0;
}