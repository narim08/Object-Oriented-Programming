#include "A.h"
#include <iostream>
using namespace std;

A::A(double Num):num(Num) { //생성자에서 멤버 이니셜라이저후 출력
	
	cout << "Class A is created with " << num << endl;
}
A::~A() { //소멸자 출력
	cout << "Class A is destroyed with " << num << endl;
}