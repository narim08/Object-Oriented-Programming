#include "Clock.h"
#include <iostream>
using namespace std;

int main()
{
	Clock time; //Ŭ���� ��ü ����
	
	/*����ڷκ��� ��ȯ�� �� �Է� ����*/
	int sec;
	cin >> sec;

	time.setTime(sec); //Ŭ������ ����
	
	return 0;
}