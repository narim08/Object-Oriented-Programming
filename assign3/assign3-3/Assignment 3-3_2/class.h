#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
protected:
	int age;
	char name[32];

public:
	Person();
	~Person();

	virtual void Say() = 0; //���� �����Լ�(�ڽ�Ŭ�������� �������̵�)
};

class Professor:public Person
{
protected:
	char professorNum[11];
	char major[32];

public:
	Professor();
	~Professor();

	int getAge();
	char* getName();
	char* getProfessorNum();
	char* getMajor();

	void setAge(int age);
	void setName(char* name);
	void setProfessorNum(char* professorNum);
	void setMajor(char* major);

	void Say(); //���� ���
};

class Student :public Person
{
protected:
	char studentNum[11];
	char major[32];
	int schoolYear;

public:
	Student();
	~Student();

	int getAge();
	char* getName();
	char* getStudentNum();
	char* getMajor();
	int getSchoolYear();

	void setAge(int age);
	void setName(char* name);
	void setStudentNum(char* studentNum);
	void setMajor(char* major);
	void setSchoolYear(int year);

	void Say(); //���� ���
};