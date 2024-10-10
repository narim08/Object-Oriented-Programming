#include "class.h"

/*Person Ŭ���� ����Լ� ����*/
Person::Person() :age(0), name{ NULL }{}
Person::~Person(){}


/*Professor Ŭ���� ����Լ� ����*/
Professor::Professor(): professorNum{NULL}, major{NULL}{}
Professor::~Professor(){}

int Professor::getAge() {
	return age;
}

char* Professor::getName() {
	return name;
}

char* Professor::getProfessorNum() {
	return professorNum;
}

char* Professor::getMajor() {
	return major;
}

void Professor::setAge(int age) {
	this->age = age;
}

void Professor::setName(char* name) {
	strncpy(this->name, name, 31); //������ ũ������� ����
	this->name[31] = NULL; //���ڿ� �� ����
}

void Professor::setProfessorNum(char* professorNum) {
	strncpy(this->professorNum, professorNum, 10);
	this->professorNum[10] = NULL;
}

void Professor::setMajor(char* major) {
	strncpy(this->major, major, 31);
	this->major[31] = NULL;
}

void Professor::Say() { //���� ���
	cout << "I'm professor of KW University." << endl;
	cout << "My name is " << getName() << "." << endl;
	cout << "I'm " << getAge() << " years old and my professor number is " << professorNum << "." << endl;
	cout << "I'm majoring in " << getMajor() << "." << endl;
}


/*Student Ŭ���� ����Լ� ����*/
Student::Student() :studentNum{ NULL }, major{ NULL }, schoolYear(0){}
Student::~Student(){}

int Student::getAge() {
	return age;
}

char* Student::getName() {
	return name;
}

char* Student::getStudentNum() {
	return studentNum;
}

char* Student::getMajor() {
	return major;
}

int Student::getSchoolYear() {
	return schoolYear;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setName(char* name) {
	strncpy(this->name, name, 31);
	this->name[31] = NULL;
}

void Student::setStudentNum(char* studentNum) {
	strncpy(this->studentNum, studentNum, 10);
	this->studentNum[10] = NULL;
}

void Student::setMajor(char* major) {
	strncpy(this->major, major, 31);
	this->major[31] = NULL;
}

void Student::setSchoolYear(int year) {
	schoolYear = year;
}

void Student::Say() { //���� ���
	cout << "I'm student of KW University." << endl;
	cout << "My name is " << getName() << "." << endl;
	cout << "I'm " << getAge() << " years old and I'm " << schoolYear << " grade." << endl;
	cout << "My student number is " << getStudentNum() << "." << endl;
	cout << "I'm majoring in " << getMajor() << "." << endl;
}