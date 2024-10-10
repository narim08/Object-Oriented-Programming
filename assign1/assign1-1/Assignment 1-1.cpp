#include <iostream>
#include <cmath>
using namespace std;
void Triangle(int n);

int main()
{
	int k, N; 

	while (1) { //����� �� ������ ���� �Է¹��� ������ �ݺ�
		cout << "Input k: ";
		cin >> k;
		if (1 <= k && k <= 8)
			break;
	}
	
	N = 3 * (int)pow(2, k - 1); //N�� ���

	Triangle(N); //�Լ��� ����
	
	return 0;
}

void Triangle(int n) //�ÿ����ɽ�Ű �ﰢ�� ������ �Լ�
{
	/*�⺻ �ﰢ�� �迭 ����*/
	char tri[3][6] = { "  $  ", 
					   " $ $ ",
					   "$$$$$" };

	/*���޹��� N���� ���� ���*/
	for (int a = 0; a < (n / 2) - 2; a++){
		cout << " ";
	}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				cout << tri[i][j];
			}
			cout << endl;
		}
		cout << endl;
}