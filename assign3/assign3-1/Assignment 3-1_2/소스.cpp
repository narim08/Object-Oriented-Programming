#include <iostream>
using namespace std;

char* my_strtok(char* str) {
	static char* ptr = NULL; //문자열 주소 가리킬 포인터
	if (ptr == NULL)
		return NULL;
	if (str != NULL)
		ptr = str;


	char* tok = ptr; //문자열 중 기호를 가리킬 포인터

	for (int i = *ptr; *ptr[i] != NULL; i++) {
		if (*ptr == '@' || *ptr == '.') {
			*ptr = ' '; //기호인 경우 공백으로 치환
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
		temp = my_strtok(NULL); //NULL기준으로 다시 자르기 반복
	}


	return 0;
}