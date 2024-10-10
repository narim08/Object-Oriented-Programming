#include "Matrix.h"

int main()
{
	double m1[3][3], m2[3][3]; //�Է� ���� ���

	cout << "3x3 ��� 1 �Է�" << endl;
	for (int i = 0; i< 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m1[i][j];
		}
	}
	cout << endl;
	Matrix mat1(m1); //��� ��ü �����ϸ鼭 �ٷ� �ʱ�ȭ

	cout << "3x3 ��� 2 �Է�" << endl;
	for (int i = 0; i< 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m2[i][j];
		}
	}
	cout << endl;
	Matrix mat2(m2); //��� ��ü �����ϸ鼭 �ٷ� �ʱ�ȭ
	cout << endl;


	cout << "/* ���� */" << endl;
	mat1 += mat2;
	mat1.printMat(); //��� ���
	cout << endl;

	cout << "/* ���� */" << endl;
	mat1 -= mat2;
	mat1.printMat();
	cout << endl;

	cout << "/* ���� */" << endl;
	Matrix res; //��� ������ ���
	res = mat1 * mat2;
	res.printMat();
	cout << endl;

	return 0;
}