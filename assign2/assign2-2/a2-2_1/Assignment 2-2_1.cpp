#include <iostream>
using namespace std;

int main()
{
	int i = 0, j = 0, k = 0;
	char Arr[100]={}; //�Է� ���� ��ü �迭
	char str[100] = {}; //��ø �迭 �и� ����
	char sstr[10] = {}; //��ø �迭 �� �迭 ��� ����
	char ex[5] = "exit"; //���� ���ڿ�


	scanf_s("%[^\n]s", Arr, 100);//�������� �Է¹ޱ�

	/*��ø �迭 ���� ����*/
	for (i = 1; Arr[i] != NULL; i++) { //��ü ���ڿ� �˻�
		if (Arr[i] == '[') { //���ȣ ���� ���� ���� ��ø �迭 ����
			for (i = i + 1; Arr[i] != ']'; i++) {
				str[j++] = Arr[i];
			}
		}
	}

	while (1) { //exit �Է� ������ �ݺ�
		char idx = 'x'; //��� �迭 �ε��� �� x�� �ʱ�ȭ
		char arr[10] = {}; //����� �迭 ��� ����
		cin >> arr;

		/*����� �ε��� �� ã��*/
		for (i = 0; arr[i] != NULL; i++) {
			if (arr[i] == '[') {
				idx = arr[i + 1]; //���ȣ ���� �ε��� ���� ���� 
			}
		}

		/*���*/
		if (idx == '3') { //��ø �迭 ��ġ�� ���
			cout << '[' << str << ']' << endl;
			cout << endl;
		}
		else if (idx == '1') { //���� ��ø �迭 ��ġ�� ���
			for (i = 0; str[i] != NULL; i++) { //���ڿ� ������ �˻��ؼ�
				if (str[i] == ',') { //�޸� ��ġ ã����
					for (i = i + 2; str[i] != NULL; i++) { //�� ���� ���ڿ� ����
						sstr[k++] = str[i];
					}
				}
			}
			cout << sstr << endl;
			cout << endl;
		}
		else if (strcmp(arr, ex)==0) { //���α׷� �����
			exit(1);
		}
		else { //�ε��� ���� �� �� ��� �迭 ��ü ���
			cout << Arr << endl;
			cout << endl;
		}
	}
	
	return 0;
}