#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "oopstd.h" //���� ��������� �Լ��� ���ҽ� �� �κ� �ּ�ó��
using namespace std;

struct MEMcpy{ //memcpy���� ���� ����ü
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
	memcpy(person.name, Name, strlen(Name) + 1); //�̸� ����
	int Age = 21;
	memcpy(&person.age, &Age, 1); //���� ����
	cout << "memcpy: " << person.name << ", " << person.age << endl;
	cout << endl;


	cout << "/* strcmp */" << endl;
	char str1[30] = "abcde";
	char str2[30]="abcd!";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	if (strcmp(str1, str2)==0) { //���ڿ� ��
		cout << "������ ���ڿ��Դϴ�." << endl;
	}
	else {
		cout << "���� �ٸ� ���ڿ��Դϴ�." << endl;
	}
	cout << endl;


	cout << "/* strncmp */" << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "�� ����: 3" << endl;
	if (strncmp(str1, str2, 3)==0) { //���ڿ� ��
		cout << "������ ���ڿ��Դϴ�." << endl;
	}
	else {
		cout << "���� �ٸ� ���ڿ��Դϴ�." << endl;
	}
	cout << endl;


	cout << "/* strcpy */" << endl;
	char dest[30] = {};
	char sour[30] = "strcpy test";
	strcpy(dest, sour); //���ڿ� ����
	cout << "str: " << sour << endl;
	cout << "strcpy: " << dest << endl;
	cout << endl;

	cout << "/* strncpy */" << endl;
	char dest2[30] = {};
	char sour2[30] = "strncpy test";
	strncpy(dest2, sour2, 3);
	cout << "str: " << sour2 << endl;
	cout << "���� ����: 3"<< endl;
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