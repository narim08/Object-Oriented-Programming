#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Empolyee
{
private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	Empolyee(); //기본 생성자
	Empolyee(char* name, int age, char* country, char* job); //생성자에서 초기화
	bool isNameCorrect(char* name); //이름 일치 검사
	void print(); //총 출력
	void change(char* name, int age, char* country, char* job); //정보 수정
};

