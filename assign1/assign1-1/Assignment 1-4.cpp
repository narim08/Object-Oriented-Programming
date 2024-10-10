#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, d, e, f, g, h, i; //배열 값 계산을 위한 기호
	double det_A; //역행렬 조건 판단 변수
	int A[3][3]= {}; //사용자에게 입력받을 배열
	double C[3][3] = {}; //여인수행렬 저장할 배열
	double C_T[3][3] = {}; //수반행렬(전치) 저장할 배열
	

	/*사용자에게 3*3 배열 값 입력받음*/
	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	cout << endl;

	/*계산을 위해 기호로 치환*/
	a = A[0][0], b = A[0][1], c = A[0][2];
	d = A[1][0], e = A[1][1], f = A[1][2];
	g = A[2][0], h = A[2][1], i = A[2][2];
	
	det_A = ((a * e * i) + (b * f * g) + (c * d * h) - (c * e * g) - (a * f * h) - (b * d * i));
	if (det_A == 0) { //det_A가 0이 되면 역행렬은 존재하지 않음
		cout << "The inverse matrix does not exist." << endl;
		exit(1); //종료
	}


	/*여인수행렬 구하기*/
	C[0][0] = e * i - f * h, C[0][1] = (-1) * (d * i - f * g), C[0][2] = d * h - e * g;
	C[1][0] = (-1) * (b * i - c * h), C[1][1] = a * i - c * g, C[1][2] = (-1) * (a * h - b * g);
	C[2][0] = b * f - c * e, C[2][1] = (-1) * (a * f - c * d), C[2][2] = a * e - b * d;


	/*전치행렬 구하고 det_A의 역수를 곱하여 역행렬 구하기*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			C_T[i][j] = ((1/det_A) * (C_T[i][j] = C[j][i]));
		}
	}


	/*출력*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << C_T[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}