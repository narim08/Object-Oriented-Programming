#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
	char fname[50]; //�ؽ�Ʈ ���� �̸��� �Է� ���� �迭
	char fstr[100]; //���� ���� ������� ������ �迭
	char arr1[10], arr2[50]; //ã���� �ϴ� ���ڿ� �Է� ���� �迭
	char Arr1[10], Arr2[50]; //Ž���� �迭
	int num;//ã���� �ϴ� ���� ����
	int n1=0, n2=0; //���ϵ�ī�� �������� ��ġ�� ������ ����
	int i = 0;


	/*����ڷκ��� ���� �Է� ����*/
	cout << "Input file name: ";
	cin >> fname;
	cin >> num;
	cin >> arr1;
	cin >> arr2;
	cout << endl << endl;

	ifstream finput; //�б�� ���� ��Ʈ�� ��ü ����
	finput.open(fname); //�Է¹��� ���� ����

	/*������ ã�� �� ���� ��� ���� �ȳ���*/
	if (!finput) { 
		cout << "������ �� �� �����ϴ�." << endl;
		exit(1);
	}


	/*ù��° ���ڿ�*/
	for (i = 0; arr1[i]!='*'; i++) { //* ������ ������ �ݺ�
		n1 = i;
		if (arr1[i] == NULL) { //*�� �ƴ� ���
			for (i = 0; arr1[i] != '?'; i++) { //? ������ ������ �ݺ�
				n1 = i;
				if (arr1[i] == NULL) { //���ϵ� ī�尡 ���� ��� ����
					cout << "�Է��� �ùٸ��� �ʽ��ϴ�." << endl;
					exit(1);
				}
			}
		} 
	}
	n1++; //���ϵ�ī�� ��ġ�� n�� ����
	strncpy(Arr1, arr1, n1); //���ο� �迭�� �̸������� ����
	Arr1[n1] = '\0'; //���� ���ϵ�ī�� ��ġ�� ���ڿ� �� �˸� �ֱ�
	

	/*�ι�° ���ڿ�*/
	for (i = 0; arr2[i] != '?'; i++) { //* ������ ������ �ݺ�
		n2 = i;
		if (arr2[i] == NULL) { //*�� �ƴ� ���
			for (i = 0; arr2[i] != '*'; i++) { //? ������ ������ �ݺ�
				n2 = i;
				if (arr2[i] == NULL) { //���ϵ� ī�尡 ���� ��� ����
					cout << "�Է��� �ùٸ��� �ʽ��ϴ�." << endl;
					exit(1);
				}
			}
		}
	}
	n2++; //���ϵ�ī�� ��ġ�� n�� ����
	strncpy(Arr2, arr2, n2); //���ο� �迭�� �̸������� ����
	Arr2[n2] = '\0'; //���� ���ϵ�ī�� ��ġ�� ���ڿ� �� �˸� �ֱ�
	

	/*���ڿ� �˻�*/
	while (!finput.eof()) { //������ ���� �����ϱ� ������ �ݺ�
		finput.getline(fstr, 100); //�� �پ� �ҷ�����
		char* ptr = strstr(fstr, Arr1); //�ҷ��� ���ڿ��� �˻��� ���ڿ� ��ġ ���� Ž��
		if (ptr != NULL) { //ã���� NULL���� �ƴϹǷ�
			cout << fstr << endl; //��ġ�� ���ڿ� ���
		}
	}
	finput.close();



	/*�ι�° ���ڿ� �˻��� ���� ���� �ٽ� ����*/
	ifstream finput2; //�б�� ���� ��Ʈ�� ��ü2 ����
	finput2.open(fname);

	while (!finput2.eof()) {
		finput2.getline(fstr, 100);
		char* ptr2 = strstr(fstr, Arr2);
		if (ptr2 != NULL) {
			cout << fstr << endl;
		}
	}
	finput2.close();

	return 0;
}