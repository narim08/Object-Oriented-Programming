#include "Matrix.h"

Matrix::Matrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = 0;
		}
	}
}

Matrix::Matrix(double mat[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->mat[i][j] = mat[i][j];
		}
	}
}

Matrix::~Matrix(){}


void Matrix::printMat() { //��� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}


/*������ �����ε�*/
Matrix Matrix::operator += (const Matrix& p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] += p.mat[i][j];
		}
	}
	return mat;
}

Matrix Matrix::operator -= (const Matrix& p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] -= p.mat[i][j];
		}
	}
	return mat;
}

Matrix Matrix::operator * (const Matrix& p) {
	Matrix res; //����� ���� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int a = 0; a < 3; a++) {
				res.mat[i][j] += mat[i][a] * p.mat[a][j];
			}
		}
	}
	return res.mat;
}