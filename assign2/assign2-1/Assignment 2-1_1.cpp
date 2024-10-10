#include <iostream>
using namespace std;

bool emp(int t) { //������ ����ִ��� Ȯ���ϴ� �Լ�
	if (t < 0) //������� ��
		return true;
	else
		return false;
}

void empty(int t) //������ ����ִ��� Ȯ���ϰ� ����ϴ� �Լ�
{
	if (t < 0) //������� ��
		cout << '1' << endl;
	else
		cout << '0' << endl;
}

void push(int* stack, int *t) //���ÿ� �����ϴ� �Լ�
{
	int n;
	cin >> n;
	stack[++*t] = n; //�ε����� ���� �� ���� ����
}

int pop(int* stack, int *t) { //������ top�� ��� �� �����ϴ� �Լ�
	if (!emp(*t)) { //������ ������� ������
		cout << stack[*t] << endl; //top ��� ��
		return stack[(*t)--]; //top�� ��ȯ �� �ε��� ����
	}
	else {
		cout << "������ ����ֽ��ϴ�." << endl;
		return NULL; 
	}
}

void top(int* stack, int *t) { //������ top�� ����ϴ� �Լ�
	if (!emp(*t)) { //������ ������� ������
		cout << stack[*t] << endl; //top ���
	}
	else
		cout << "������ ����ֽ��ϴ�." << endl;
}

void print(int* stack, int *t) { //������ �� �Ʒ����� ����ϴ� �Լ�
	for (int i = 0; i <= *t; i++) {
		cout << stack[i] << ' ';
	}
	cout << endl;
}


int main()
{
	int stack[128] = {}; //���� ����
	int t = -1; //top�� ����ų �����ͷ� ���� ����
	char str[10]={}; //��ɾ� �Է� ���� �迭

	while (1) { //exit �Է±��� �ݺ�
		cin >> str;
		if (!strcmp(str, "push")) {
			push(stack, &t);
		}
		else if (!strcmp(str, "pop")) {
			pop(stack, &t);
		}
		else if (!strcmp(str, "top")) {
			top(stack, &t);
		}
		else if (!strcmp(str, "print")) {
			print(stack, &t);
		}
		else if (!strcmp(str, "empty")) {
			empty(t);
		}
		else {
			exit(1);
			break;
		}
	}
	return 0;
}