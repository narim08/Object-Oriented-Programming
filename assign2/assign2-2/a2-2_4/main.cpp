#include "Clock.h"
#include <iostream>
using namespace std;

int main()
{
	Clock time; //클래스 객체 생성
	
	/*사용자로부터 변환할 초 입력 받음*/
	int sec;
	cin >> sec;

	time.setTime(sec); //클래스에 전달
	
	return 0;
}