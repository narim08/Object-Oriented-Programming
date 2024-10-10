#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, d, e, f, g, h, i; //�迭 �� ����� ���� ��ȣ
	double det_A; //����� ���� �Ǵ� ����
	int A[3][3]= {}; //����ڿ��� �Է¹��� �迭
	double C[3][3] = {}; //���μ���� ������ �迭
	double C_T[3][3] = {}; //�������(��ġ) ������ �迭
	

	/*����ڿ��� 3*3 �迭 �� �Է¹���*/
	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	cout << endl;

	/*����� ���� ��ȣ�� ġȯ*/
	a = A[0][0], b = A[0][1], c = A[0][2];
	d = A[1][0], e = A[1][1], f = A[1][2];
	g = A[2][0], h = A[2][1], i = A[2][2];
	
	det_A = ((a * e * i) + (b * f * g) + (c * d * h) - (c * e * g) - (a * f * h) - (b * d * i));
	if (det_A == 0) { //det_A�� 0�� �Ǹ� ������� �������� ����
		cout << "The inverse matrix does not exist." << endl;
		exit(1); //����
	}


	/*���μ���� ���ϱ�*/
	C[0][0] = e * i - f * h, C[0][1] = (-1) * (d * i - f * g), C[0][2] = d * h - e * g;
	C[1][0] = (-1) * (b * i - c * h), C[1][1] = a * i - c * g, C[1][2] = (-1) * (a * h - b * g);
	C[2][0] = b * f - c * e, C[2][1] = (-1) * (a * f - c * d), C[2][2] = a * e - b * d;


	/*��ġ��� ���ϰ� det_A�� ������ ���Ͽ� ����� ���ϱ�*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			C_T[i][j] = ((1/det_A) * (C_T[i][j] = C[j][i]));
		}
	}


	/*���*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << C_T[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}