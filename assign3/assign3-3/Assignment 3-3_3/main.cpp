#include "Matrix.h"

int main()
{
	double m1[3][3], m2[3][3]; //입력 받을 행렬

	cout << "3x3 행렬 1 입력" << endl;
	for (int i = 0; i< 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m1[i][j];
		}
	}
	cout << endl;
	Matrix mat1(m1); //행렬 객체 생성하면서 바로 초기화

	cout << "3x3 행렬 2 입력" << endl;
	for (int i = 0; i< 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m2[i][j];
		}
	}
	cout << endl;
	Matrix mat2(m2); //행렬 객체 생성하면서 바로 초기화
	cout << endl;


	cout << "/* 덧셈 */" << endl;
	mat1 += mat2;
	mat1.printMat(); //행렬 출력
	cout << endl;

	cout << "/* 뺄셈 */" << endl;
	mat1 -= mat2;
	mat1.printMat();
	cout << endl;

	cout << "/* 곱셈 */" << endl;
	Matrix res; //결과 저장할 행렬
	res = mat1 * mat2;
	res.printMat();
	cout << endl;

	return 0;
}