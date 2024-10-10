#include <iostream>
using namespace std;

/*�ŵ����� �Լ�*/
double POW(int x, int n) //x^n ����
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

/*���丮�� �Լ�*/
double FAC(int n)
{
	if (n == 0) {
		return 1;
	}
	else {
		return FAC(n - 1) * n;
	}
}

/*sin �Լ�*/
double SIN(double x, int n) //n�� ��Ȯ�� �ø��� ��
{
	if (n == 0) {
		return x;
	}
	else { //���Ϸ� �޼� ���� �̿�
		double s = (POW(-1, n) / FAC(2 * n + 1)) * POW(x, 2 * n + 1);
		return SIN(x, (n - 1)) + s; //�޼� �� ����
	}

}

/*cos �Լ�*/
double COS(double x, int n) //n�� ��Ȯ�� �ø��� ��
{
	if (n == 0) {
		return 1;
	}
	else { //���Ϸ� �޼� ���� �̿�
		double c = (POW(-1, n) / FAC(2 * n)) * POW(x, 2 * n);
		return COS(x, (n - 1)) + c; //�޼� �� ����
	}
}


void mat(double T[][3], int* in) //��� ��� & ��� �Լ�
{
	int arr[3] = {}; //��� ������ �迭
	double sum;

	/*��� ���� ���*/
	for (int i = 0; i < 3; i++) {
		sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += T[i][j] * in[j];
		}
		arr[i] = sum;
	}

	/*��� ���*/
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}
}

int main()
{
	const double PI = 3.141592; //���� �� ����
	int d, r = 0; //����, ���� ����
	int x, y, z; //�Է� ���� ����
	double s, c; //sin, cos�� ����

	cout << "Degrees: "; cin >> d;
	cout << "Coordinate: "; cin >> x >> y >> z;

	/*����ڷκ��� �Է� ���� �迭*/
	int in[3] = { x, y, z };

	/*�ﰢ�Լ� ��� (��Ȯ�� �⺻ ��, �� �� ���� �ִ� �� �з�)*/
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
	default: //�⺻ ������ �ƴ� �ٸ� ��� ���, ������ �̿��� ���(���� o)
		r = (d * PI) / 180;
		s = SIN(r, 10); c = COS(r, 10);
	}

	double T[3][3] = { { -c, s, 0}, {s, c, 0}, {0, 0, 0} };
	mat(T, in);

	return 0;
}
