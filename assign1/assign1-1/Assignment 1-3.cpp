#include <iostream>
using namespace std;


void swap(int *x, int *y) //y���� �� Ŭ �� ���� �� �ٲٱ� ���� �Լ�(�ּҰ� �̿�)
{
	int t = *x;
	*x = *y;
	*y = t;
}

int gcd(int x, int y) //����Լ��� �ִ����� ���ϱ�
{
	if (y == 0) //y�� 0�� �Ǹ� �� ���� ���̹Ƿ� gcd�� x�� ��
		return x; //���� x�� ��ȯ
	else
		return gcd(y, x % y); //y�� 0�� �Ǳ� �������� ��� �ݺ��ؼ� �������� ���ؾߵǴ� ����� ȣ����
}

int main()
{
	int x, y;
	//����ڷκ��� �� ���� �Է¹���
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;

	if (x < y) {  //�� �� x�� �� ū ���� ������ ����
		swap(&x, &y); //y�� �� Ŭ �� ���� �� ��ȯ��
	}
	
	int LCM = x*y / gcd(x, y); //�ּҰ���� ���ϴ� ��

	cout << "LCM: " << LCM << endl;

	return 0;
}