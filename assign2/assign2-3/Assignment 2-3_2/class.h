#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
	char* name;
	int age;
	char* class_name;

public:
	Student(); 
	Student(char*name, int age, char*class_name); //�ʱ�ȭ�� ������
	char* get_name(); //�ش� ��ü�� �̸� �� ��ȯ
	int get_age(); //�ش� ��ü�� ���� �� ��ȯ
	char* get_class_name(); //�ش� ��ü�� �й� �� ��ȯ
};

class School
{
private:
	class Student *student_list[100]; //�л� Ŭ���� ��ü �迭
	int size; //�� ��ü�� ũ�� ����

public:
	School();
	void new_student(char*name, int age, char*class_name); //�л� ���� �߰�
	void print_all(); //�л� ���� ��ü ���
	void print_class(int idx); //�ش� �й� ��ü ���
	void sort_by_name(); //��ü �迭�� �̸� �� ����
	int showSize(); //��ü �迭�� size ���޿�
	bool Class_correct(char* class_name, int idx); //�й� �̸� �˻�
};