#include <iostream>
using namespace std;

char* my_strtok(char* str) {
	static char* ptr; //���ڿ� �ּ� ����ų ������ �������� ����

	if (str != NULL) { //�� ���ڿ��� �ƴϸ� �����Ϳ� ����
		ptr = str;
	}
	/*���� ó��*/
	else { 
		str = ptr;
	}
	if (*ptr == NULL) { 
		return NULL;
	}

	char* tok = ptr; //ptr�� static�̹Ƿ� �Լ� ��ȣ�� �� ���� ���ڿ� ���� ��ġ ����
	while (*ptr) {
		if (*ptr == '@' || *ptr == '.') { //Ư�� ������ ���
			*ptr = NULL; //NULL�� ġȯ
			++ptr; //���� ���ڷ� �̵�
			return tok; //�ش� ���ڿ� �ּ� ��ȯ
		}
		++ptr;
	}
	return tok; //�� �ڸ� ���
}


int main()
{
	char str[50]={}; //�̸��� �Է� ���� �迭
	cin >> str;
	
	/*ù��°�� �ڸ� ���ڿ� ���*/
	cout << my_strtok(str) << endl;

	/*�ι�°���ʹ� ���� ȣ�� ���ĺ��� �ٽ� �˻�*/
	char* temp2 = my_strtok(NULL);
	while (temp2) { //���ڿ� ������ �ݺ�
		cout << temp2 << endl;
		temp2 = my_strtok(NULL);
	}
	return 0;
}