#include <iostream>
using namespace std;

char* my_strtok(char* str) {
	static char* ptr = NULL; //���ڿ� �ּ� ����ų ������
	if (ptr == NULL)
		return NULL;
	if (str != NULL)
		ptr = str;


	char* tok = ptr; //���ڿ� �� ��ȣ�� ����ų ������

	for (int i = *ptr; *ptr[i] != NULL; i++) {
		if (*ptr == '@' || *ptr == '.') {
			*ptr = ' '; //��ȣ�� ��� �������� ġȯ
			return tok;
		}
	}
	return tok;
}


int main()
{
	char str[50]={};
	cin >> str;

	char* temp = my_strtok(str);
	while (temp != NULL) {
		cout << temp;
		temp = my_strtok(NULL); //NULL�������� �ٽ� �ڸ��� �ݺ�
	}


	return 0;
}