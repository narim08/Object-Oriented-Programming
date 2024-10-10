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
	Student(char*name, int age, char*class_name); //초기화할 생성자
	char* get_name(); //해당 객체의 이름 값 반환
	int get_age(); //해당 객체의 나이 값 반환
	char* get_class_name(); //해당 객체의 분반 값 반환
};

class School
{
private:
	class Student *student_list[100]; //학생 클래스 객체 배열
	int size; //위 객체의 크기 변수

public:
	School();
	void new_student(char*name, int age, char*class_name); //학생 정보 추가
	void print_all(); //학생 정보 전체 출력
	void print_class(int idx); //해당 분반 전체 출력
	void sort_by_name(); //객체 배열들 이름 순 정렬
	int showSize(); //객체 배열의 size 전달용
	bool Class_correct(char* class_name, int idx); //분반 이름 검색
};