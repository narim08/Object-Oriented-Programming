#include "A.h"
#include <iostream>
using namespace std;

A::A(double Num):num(Num) { //�����ڿ��� ��� �̴ϼȶ������� ���
	
	cout << "Class A is created with " << num << endl;
}
A::~A() { //�Ҹ��� ���
	cout << "Class A is destroyed with " << num << endl;
}