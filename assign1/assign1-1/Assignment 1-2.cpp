#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a=0, b=0, c=0;

	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "c: "; cin >> c;

	if (a == 0) { //�и� 0�� �Ǵ� ��� ����
		cout << "Unexpected factor of a quadratic term" << endl;
		exit(1);
	}
	
	float D = (b * b) - (4 * a * c); //�Ǻ���

	/*b>0�� ��쿡 ù��° ��(+) ���� ������ ����*/
	float X1 = (2 * c) / ((-b) - sqrt(D)); //ù��° ��
	float X2 = ((-b) - sqrt(D)) / (2 * a); //�ι�° ��

	/*b<0�� ��쿡 �ι�° ��(-) ���� ������ ����*/
	float x1 = ((-b) + sqrt(D)) / (2 * a); //ù��° ��
	float x2 = (2 * c) / ((-b) + sqrt(D)); //�ι�° ��


	if (D < 0) { //����� ���� ���
		cout << "The equation has no real number solutions." << endl;
	}
	else if (D==0) { //�߱��� ���� ���
		cout << "X1, X2: " << X1 << "(double root)" << endl;
	}
	else { //���� �ٸ� �Ǳ��� ���� ���
		if (b > 0) {
			cout << "X1: " << X1 << ", X2: " << X2 << endl;
		}
		else {
			cout << "X1: " << x1 << ", X2: " << x2 << endl;
		}
	}

	return 0;
}