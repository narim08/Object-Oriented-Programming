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
	Empolyee(); //�⺻ ������
	Empolyee(char* name, int age, char* country, char* job); //�����ڿ��� �ʱ�ȭ
	bool isNameCorrect(char* name); //�̸� ��ġ �˻�
	void print(); //�� ���
	void change(char* name, int age, char* country, char* job); //���� ����
};

