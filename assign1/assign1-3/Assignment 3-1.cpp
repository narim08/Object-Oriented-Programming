#include <iostream>
using namespace std;

/*거듭제곱 함수*/
double POW(int x, int n) //x^n 형태
{
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return POW(x * x, n / 2);
	}
	else {
		return x * POW(x * x, (n - 1) / 2);
	}
}

/*팩토리얼 함수*/
double FAC(int n)
{
	if (n == 0) {
		return 1;
	}
	else {
		return FAC(n - 1) * n;
	}
}

/*sin 함수*/
double SIN(double x, int n) //n은 정확도 올리는 용
{
	if (n == 0) {
		return x;
	}
	else { //테일러 급수 공식 이용
		double s = (POW(-1, n) / FAC(2 * n + 1)) * POW(x, 2 * n + 1);
		return SIN(x, (n - 1)) + s; //급수 합 전개
	}

}

/*cos 함수*/
double COS(double x, int n) //n은 정확도 올리는 용
{
	if (n == 0) {
		return 1;
	}
	else { //테일러 급수 공식 이용
		double c = (POW(-1, n) / FAC(2 * n)) * POW(x, 2 * n);
		return COS(x, (n - 1)) + c; //급수 합 전개
	}
}


void mat(double T[][3], int* in) //행렬 계산 & 출력 함수
{
	int arr[3] = {}; //결과 저장할 배열
	double sum;

	/*행렬 곱셈 계산*/
	for (int i = 0; i < 3; i++) {
		sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += T[i][j] * in[j];
		}
		arr[i] = sum;
	}

	/*행렬 출력*/
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}
}

int main()
{
	const double PI = 3.141592; //파이 값 고정
	int d, r = 0; //각도, 라디안 변수
	int x, y, z; //입력 받을 변수
	double s, c; //sin, cos값 변수

	cout << "Degrees: "; cin >> d;
	cout << "Coordinate: "; cin >> x >> y >> z;

	/*사용자로부터 입력 받은 배열*/
	int in[3] = { x, y, z };

	/*삼각함수 계산 (정확한 기본 값, 그 외 오차 있는 값 분류)*/
	switch (d) {
	case 0 :
		s = 0; c = 1;
		break;
	case 30:
		s = 1 / 2; c = sqrt(3) / 2;
		break;
	case 45:
		s = sqrt(2) / 2; c = sqrt(2) / 2;
		break;
	case 60:
		s = sqrt(3) / 2; c = 1 / 2;
		break;
	case 90:
		s = 1; c = 0;
		break;
	default: //기본 각도가 아닌 다른 모든 경우, 공식을 이용해 계산(오차 o)
		r = (d * PI) / 180;
		s = SIN(r, 10); c = COS(r, 10);
	}

	double T[3][3] = { { -c, s, 0}, {s, c, 0}, {0, 0, 0} };
	mat(T, in);

	return 0;
}
