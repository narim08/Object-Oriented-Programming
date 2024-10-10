#include <iostream>
using namespace std;


void swap(int *x, int *y) //y값이 더 클 때 서로 값 바꾸기 위한 함수(주소값 이용)
{
	int t = *x;
	*x = *y;
	*y = t;
}

int gcd(int x, int y) //재귀함수로 최대공배수 구하기
{
	if (y == 0) //y가 0이 되면 다 나눈 것이므로 gcd는 x가 됨
		return x; //따라서 x값 반환
	else
		return gcd(y, x % y); //y가 0이 되기 전까지는 계속 반복해서 나머지를 구해야되니 재귀적 호출함
}

int main()
{
	int x, y;
	//사용자로부터 두 수를 입력받음
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;

	if (x < y) {  //둘 중 x에 더 큰 수를 놓도록 설정
		swap(&x, &y); //y가 더 클 때 서로 값 교환함
	}
	
	int LCM = x*y / gcd(x, y); //최소공배수 구하는 식

	cout << "LCM: " << LCM << endl;

	return 0;
}