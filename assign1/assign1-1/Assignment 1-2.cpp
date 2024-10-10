#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a=0, b=0, c=0;

	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "c: "; cin >> c;

	if (a == 0) { //분모가 0이 되는 경우 종료
		cout << "Unexpected factor of a quadratic term" << endl;
		exit(1);
	}
	
	float D = (b * b) - (4 * a * c); //판별식

	/*b>0일 경우에 첫번째 근(+) 식을 변형한 계산식*/
	float X1 = (2 * c) / ((-b) - sqrt(D)); //첫번째 근
	float X2 = ((-b) - sqrt(D)) / (2 * a); //두번째 근

	/*b<0일 경우에 두번째 근(-) 식을 변형한 계산식*/
	float x1 = ((-b) + sqrt(D)) / (2 * a); //첫번째 근
	float x2 = (2 * c) / ((-b) + sqrt(D)); //두번째 근


	if (D < 0) { //허근을 가질 경우
		cout << "The equation has no real number solutions." << endl;
	}
	else if (D==0) { //중근을 가질 경우
		cout << "X1, X2: " << X1 << "(double root)" << endl;
	}
	else { //서로 다른 실근을 가질 경우
		if (b > 0) {
			cout << "X1: " << X1 << ", X2: " << X2 << endl;
		}
		else {
			cout << "X1: " << x1 << ", X2: " << x2 << endl;
		}
	}

	return 0;
}