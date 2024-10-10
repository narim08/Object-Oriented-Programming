#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Binary(char *arr, int b2) //2�������� ��ȯ
{
	int sum;
	if (b2 == 2) { //2������ ��ȯ ��
		cout << arr; //�״�� ���
	}
	else if (b2 == 8) { //8������ ��ȯ ��
		cout << (arr[0] - '0') * 2 + (arr[1] - '0'); //ó�� ���� 2�ڸ� ���� ���
		for (int i = 2; i < 8; i += 3) { //3�ڸ��� ������ 2�� �ŵ����������� ���
			cout << (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');
		}
	}
	else if (b2 == 10) { //10������ ��ȯ ��
		sum = (arr[0] - '0') * 128 + (arr[1] - '0') * 64 + (arr[2] - '0') * 32 + (arr[3] - '0') * 16 + (arr[4] - '0') * 8 + (arr[5] - '0') * 4 + (arr[6] - '0') * 2 + (arr[7] - '0');
		cout << sum;
	}
	else if (b2 == 16) { //16������ ��ȯ ��
		sum = 0;
		for (int i = 0; i < 8; i += 4) { //4�ڸ��� ������ 2�� �ŵ����������� ���
			sum = (arr[i] - '0') * 8 + (arr[i + 1] - '0') * 4 + (arr[i + 2] - '0') * 2 + (arr[i + 3] - '0');
			if (sum < 10) { //0~9������ ���ڷ� ǥ��
				cout << sum;
			}
			else { //10���� ���ĺ����� ǥ��
				switch (sum)
				{
				case 10:
					cout << 'A';
					break;
				case 11:
					cout << 'B';
					break;
				case 12:
					cout << 'C';
					break;
				case 13:
					cout << 'D';
					break;
				case 14:
					cout << 'E';
					break;
				case 15:
					cout << 'F';
					break;
				}
			}
		}
	}
}

void Octal(char *arr, int b2) //8�������� 2������ ��ȯ �� Binary()�� ����
{
	char str[20]={}; //���� ������ ���ڿ� �迭
	char str1[4] = {}, str2[4]={}, str3[4]={}; //�� ġȯ�� ���� ������ �迭
	switch (arr[0]) { //ù��° �ڸ��� ���� 2������ ġȯ
	case '0':
		str1[0] = '0'; str1[1] = '0';
		break;
	case '1':
		str1[0] = '0'; str1[1] = '1';
		break;
	case '2':
		str1[0] = '1'; str1[1] = '0';
		break;
	case '3':
		str1[0] = '1'; str1[1] = '1';
		break;
	default: //�� �� �����÷ο� �߻�
		cout << "�ùٸ��� ���� ���Դϴ�."; exit(1);
	}
	strcat(str, str1); //�� �迭�� ���ڿ� ����

	switch (arr[1]) { //�ι�° �ڸ��� ���� 2������ ġȯ
	case '0':
		str2[0] = '0'; str2[1] = '0'; str2[2] = '0';
		break;
	case '1':
		str2[0] = '0'; str2[1] = '0'; str2[2] = '1';
		break;
	case '2':
		str2[0] = '0'; str2[1] = '1'; str2[2] = '0';
		break;
	case '3':
		str2[0] = '0'; str2[1] = '1'; str2[2] = '1';
		break;
	case '4':
		str2[0] = '1'; str2[1] = '0'; str2[2] = '0';
		break;
	case '5':
		str2[0] = '1'; str2[1] = '0'; str2[2] = '1';
		break;
	case '6':
		str2[0] = '1'; str2[1] = '1'; str2[2] = '0';
		break;
	case '7':
		str2[0] = '1'; str2[1] = '1'; str2[2] = '1';
		break;
	default: //�� �� �����÷ο� �߻�
		cout << "�ùٸ��� ���� ���Դϴ�."; exit(1);
	}
	strcat(str, str2); //�� �� �迭�� �̾����

	switch (arr[2]) { //����° �ڸ��� ���� 2������ ġȯ
	case '0':
		str3[0] = '0'; str3[1] = '0'; str3[2] = '0';
		break;
	case '1':
		str3[0] = '0'; str3[1] = '0'; str3[2] = '1';
		break;
	case '2':
		str3[0] = '0'; str3[1] = '1'; str3[2] = '0';
		break;
	case '3':
		str3[0] = '0'; str3[1] = '1'; str3[2] = '1';
		break;
	case '4':
		str3[0] = '1'; str3[1] = '0'; str3[2] = '0';
		break;
	case '5':
		str3[0] = '1'; str3[1] = '0'; str3[2] = '1';
		break;
	case '6':
		str3[0] = '1'; str3[1] = '1'; str3[2] = '0';
		break;
	case '7':
		str3[0] = '1'; str3[1] = '1'; str3[2] = '1';
		break;
	default: //�� �� �����÷ο� �߻�
		cout << "�ùٸ��� ���� ���Դϴ�."; exit(1);
	}
	strcat(str, str3); //�� �� �迭�� �̾����
	Binary(str, b2); //2�������� ��ȯ�ϴ� �Լ��� ����
}

void Decimal(long n, int b2) //10�������� 2, 8������ ��ȯ
{
	if (n <= 0) { //n�� 0���ϰ� �� ������ �ݺ��� ����
		return;
	}
	else {
		Decimal(n / b2, b2); //���� ���ϴ� ������ŭ ������ �۾��� ��ͷ� �ݺ�
		cout << n % 2; //������ ���ʷ� ���
	}
}

void HexaDecimal(char *arr, int b2) //16�������� 2������ ��ȯ
{
	char str[20] = {};
	char str1[5]={}, str2[5]={};
	switch (arr[0]) { //ù��° �ڸ��� ���� 2������ ġȯ
	case '0':
		str1[0] = '0'; str1[1] = '0'; str1[2] = '0'; str1[3] = '0';
		break;
	case '1':
		str1[0] = '0'; str1[1] = '0'; str1[2] = '0'; str1[3] = '1';
		break;
	case '2':
		str1[0] = '0'; str1[1] = '0'; str1[2] = '1'; str1[3] = '0';
		break;
	case '3':
		str1[0] = '0'; str1[1] = '0'; str1[2] = '1'; str1[3] = '1';
		break;
	case '4':
		str1[0] = '0'; str1[1] = '1'; str1[2] = '0'; str1[3] = '0';
		break;
	case '5':
		str1[0] = '0'; str1[1] = '1'; str1[2] = '0'; str1[3] = '1';
		break;
	case '6':
		str1[0] = '0'; str1[1] = '1'; str1[2] = '1'; str1[3] = '0';
		break;
	case '7':
		str1[0] = '0'; str1[1] = '1'; str1[2] = '1'; str1[3] = '1';
		break;
	case '8':
		str1[0] = '1'; str1[1] = '0'; str1[2] = '0'; str1[3] = '0';
		break;
	case '9':
		str1[0] = '1'; str1[1] = '0'; str1[2] = '0'; str1[3] = '1';
		break;
	case 'A':
		str1[0] = '1'; str1[1] = '0'; str1[2] = '1'; str1[3] = '0';
		break;
	case 'B':
		str1[0] = '1'; str1[1] = '0'; str1[2] = '1'; str1[3] = '1';
		break;
	case 'C':
		str1[0] = '1'; str1[1] = '1'; str1[2] = '0'; str1[3] = '0';
		break;
	case 'D':
		str1[0] = '1'; str1[1] = '1'; str1[2] = '0'; str1[3] = '1';
		break;
	case 'E':
		str1[0] = '1'; str1[1] = '1'; str1[2] = '1'; str1[3] = '0';
		break;
	case 'F':
		str1[0] = '1'; str1[1] = '1'; str1[2] = '1'; str1[3] = '1';
		break;
	}
	strcat(str, str1); //�� ���ڿ��� ����

	switch (arr[1]) { //�ι�° �ڸ��� ���� 2������ ġȯ
	case '0':
		str2[0] = '0'; str2[1] = '0'; str2[2] = '0'; str2[3] = '0';
		break;
	case '1':
		str2[0] = '0'; str2[1] = '0'; str2[2] = '0'; str2[3] = '1';
		break;
	case '2':
		str2[0] = '0'; str2[1] = '0'; str2[2] = '1'; str2[3] = '0';
		break;
	case '3':
		str2[0] = '0'; str2[1] = '0'; str2[2] = '1'; str2[3] = '1';
		break;
	case '4':
		str2[0] = '0'; str2[1] = '1'; str2[2] = '0'; str2[3] = '0';
		break;
	case '5':
		str2[0] = '0'; str2[1] = '1'; str2[2] = '0'; str2[3] = '1';
		break;
	case '6':
		str2[0] = '0'; str2[1] = '1'; str2[2] = '1'; str2[3] = '0';
		break;
	case '7':
		str2[0] = '0'; str2[1] = '1'; str2[2] = '1'; str2[3] = '1';
		break;
	case '8':
		str2[0] = '1'; str2[1] = '0'; str2[2] = '0'; str2[3] = '0';
		break;
	case '9':
		str2[0] = '1'; str2[1] = '0'; str2[2] = '0'; str2[3] = '1';
		break;
	case 'A':
		str2[0] = '1'; str2[1] = '0'; str2[2] = '1'; str2[3] = '0';
		break;
	case 'B':
		str2[0] = '1'; str2[1] = '0'; str2[2] = '1'; str2[3] = '1';
		break;
	case 'C':
		str2[0] = '1'; str2[1] = '1'; str2[2] = '0'; str2[3] = '0';
		break;
	case 'D':
		str2[0] = '1'; str2[1] = '1'; str2[2] = '0'; str2[3] = '1';
		break;
	case 'E':
		str2[0] = '1'; str2[1] = '1'; str2[2] = '1'; str2[3] = '0';
		break;
	case 'F':
		str2[0] = '1'; str2[1] = '1'; str2[2] = '1'; str2[3] = '1';
		break;
	}
	strcat(str, str2); //�� �� �迭�� �̾� ����
	Binary(str, b2); //2�������� ��ȯ�ϴ� �Լ��� ����
}

int main()
{
	long n; char arr[9]; //10������ ����, �� �� ������ �迭
	int b1, b2; //���� ����, ��ȯ�� ����
	cin >> b1 >> b2;
	if (b1 == 10) { //10������ ���� ������ long������ ����
		cin >> n;
	}
	else { //�� �� ������ ���� ������ char������ ����
		cin >> arr;
	}

	switch (b1) {
	case 2: //���� 2�������� ��
		Binary(arr, b2); //2�������� ��ȯ�ϴ� �Լ� ȣ��
		break;
	case 8: //���� 8�������� ��
		Octal(arr, b2); //8�������� ��ȯ�ϴ� �Լ� ȣ��
		break;
	case 10: //���� 10�������� ��
		Decimal(n, b2); //10�������� ��ȯ�ϴ� �Լ� ȣ��
		break;
	case 16: //���� 16�������� ��
		HexaDecimal(arr, b2); //16�������� ��ȯ�ϴ� �Լ� ȣ��
		break;
	}
	return 0;
}