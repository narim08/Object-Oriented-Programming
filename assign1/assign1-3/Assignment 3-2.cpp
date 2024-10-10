#include <iostream>
using namespace std;

/*���� ȸ�� ���*/
void Series(int Vs, int R1, int R2)
{
	int m=0, j=0, k=0; //�и�, ����, ���μ�
	j = Vs * R2;
	m = R1 + R2;
	float Vout = j / m;
	int size = sqrt(Vout);
	int* arr = new int[size] {}; //���μ� ����� �迭 �����Ҵ�

	/*���μ� ���ϱ�*/
	for (int i = 2; i <= size; i++) {
		while ((int)Vout % i == 0) {
			arr[k++] = i; //���μ� ����
		}
	}
	int t = k;
	if (Vout != 1) {
		arr[t] = Vout;
	}

	/*��ȯ�Ҽ� �˻�*/
	int g = 0;
	for (int i = 0; i<=t; i++) {
		while (arr[i] == 2 || arr[i] == 5) {
			g++;
		}
	}
	if (g == t+1) { //���������� ���μ��� ���� 2�� 5���� ���: ���ѼҼ�
		cout << "Vout: " << j << '/' << m << " = " << Vout << endl;
	}
	else { //�� ���� ���μ��� �־� �迭 �˻簡 ���� ���� ���: ��ȯ�Ҽ�
		/*
		int mod = 0, n=1;
		mod = 10 % (int)Vout;
		char str[30];
		str[0] = mod;
		while (1) {
			mod = mod * 10 / Vout;
			str[n++] = mod;
			for (int i = 0; str[i] != NULL; i++) {
				for (int q = 0; str[q] != NULL; q++) {
					if (str[i] == str[q]) {
						break;
					}
				}
			}
		}
		char s = str[n-1];
		*/
		cout << "Vout: " << j << '/' << m << " = " << Vout << "(.��ȯ)" << endl;
	}

	delete[] arr;
}

int gcd(int mR, int R1)
{
	int t;
	while (R1 != 0) {
		t = mR % R1;
		mR = R1;
		R1 = t;
	}
	return mR;
}
int lcm(int mR, int R1)
{
	return (mR * R1) / gcd(mR, R1);
}

/*���� ȸ�� ���*/
void Parallel (int Vs, int R1, int R2, int RL)
{
	int m = 0, j = 0; //�и�, ����
	int Pr = (R2*RL)/(R2+RL); //���� ����
	int mR = R2 + RL;//���� ���׽��� �и�

	int l = lcm(mR, R1); //���� ������ �и�� R1�� �ּҰ���� ����
	int a = l / mR;//��� ���� (�ּҰ������ �������׽��� �и�� ����)
	
	j = l * Vs * ((R2 * RL) / mR); //���� ����
	m = (a * R2 * RL) + (l * R1); //���� �и�

	float Vout = j / m;
	int size = sqrt(Vout);
	if (size < 2) {
		size++;
	}
	int* arr2 = new int[size] {}; //���μ� ����� �迭 �����Ҵ�
	
	float PL = 100*Vout * ((R2 * (Vs / R1 + Pr)) / (R2 + RL));
	float Ps = Vs * (Vs / (R1 + Pr));

	/*���μ� ���ϱ�
	int k = 0;
	for (int i = 2; i <= size; i++) {
		while ((int)Vout % i == 0) {
			arr2[k] = i; //���μ� ����
			k++;
		}
	}
	int t = k;
	if (Vout != 1) {
		arr2[t] = Vout;
	}

	//��ȯ�Ҽ� �˻�
	int g = 0;
	for (int i = 0; i <= t; i++) {
		while (arr2[i] == 2 || arr2[i] == 5) {
			g++;
		}
	}
	if (g == t) { //���������� ���μ��� ���� 2�� 5���� ���: ���ѼҼ�
		cout << "Vout: " << j << '/' << m << " = " << Vout << endl;
	}
	else { //�� ���� ���μ��� �־� �迭 �˻簡 ���� ���� ���: ��ȯ�Ҽ�
		cout << "Vout: " << j << '/' << m << " = " << Vout << "(. ��ȯ)" << endl;
	}
	*/
	cout << "Vout: " << j << '/' << m << " = " << Vout << endl;
	printf("Load power ratio: %.1f%%", PL / Ps);
	delete[] arr2;
}

int main()
{
	int Vs, R1, R2, RL; //�Է� ���� ���а� ����
	cout << "Vs: "; cin >> Vs;
	cout << "R1: "; cin >> R1;
	cout << "R2: "; cin >> R2;
	cout << "R(Load): "; cin >> RL;
	cout << endl;

	if (RL == 0) { //���� ȸ���� ���
		Series(Vs, R1, R2);
	}
	else { //���� ȸ���� ���
		Parallel(Vs, R1, R2, RL);
	}

	return 0;
}