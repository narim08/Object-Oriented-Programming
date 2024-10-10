#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Binary(char *arr, int b2) //2진수에서 변환
{
	int sum;
	if (b2 == 2) { //2진수로 변환 시
		cout << arr; //그대로 출력
	}
	else if (b2 == 8) { //8진수로 변환 시
		cout << (arr[0] - '0') * 2 + (arr[1] - '0'); //처음 남는 2자리 먼저 출력
		for (int i = 2; i < 8; i += 3) { //3자리씩 나눠서 2의 거듭제곱식으로 계산
			cout << (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');
		}
	}
	else if (b2 == 10) { //10진수로 변환 시
		sum = (arr[0] - '0') * 128 + (arr[1] - '0') * 64 + (arr[2] - '0') * 32 + (arr[3] - '0') * 16 + (arr[4] - '0') * 8 + (arr[5] - '0') * 4 + (arr[6] - '0') * 2 + (arr[7] - '0');
		cout << sum;
	}
	else if (b2 == 16) { //16진수로 변환 시
		sum = 0;
		for (int i = 0; i < 8; i += 4) { //4자리씩 나눠서 2의 거듭제곱식으로 계산
			sum = (arr[i] - '0') * 8 + (arr[i + 1] - '0') * 4 + (arr[i + 2] - '0') * 2 + (arr[i + 3] - '0');
			if (sum < 10) { //0~9까지는 숫자로 표현
				cout << sum;
			}
			else { //10부터 알파벳으로 표현
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

void Octal(char *arr, int b2) //8진수에서 2진수로 변환 후 Binary()로 전달
{
	char str[20]={}; //새로 저장할 문자열 배열
	char str1[4] = {}, str2[4]={}, str3[4]={}; //각 치환한 값을 저장할 배열
	switch (arr[0]) { //첫번째 자리의 값을 2진수로 치환
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
	default: //그 외 오버플로우 발생
		cout << "올바르지 않은 수입니다."; exit(1);
	}
	strcat(str, str1); //새 배열에 문자열 저장

	switch (arr[1]) { //두번째 자리의 값을 2진수로 치환
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
	default: //그 외 오버플로우 발생
		cout << "올바르지 않은 수입니다."; exit(1);
	}
	strcat(str, str2); //그 전 배열에 이어붙임

	switch (arr[2]) { //세번째 자리의 값을 2진수로 치환
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
	default: //그 외 오버플로우 발생
		cout << "올바르지 않은 수입니다."; exit(1);
	}
	strcat(str, str3); //그 전 배열에 이어붙임
	Binary(str, b2); //2진수에서 변환하는 함수로 전달
}

void Decimal(long n, int b2) //10진수에서 2, 8진수로 변환
{
	if (n <= 0) { //n이 0이하가 될 때까지 반복을 위함
		return;
	}
	else {
		Decimal(n / b2, b2); //몫을 원하는 진수만큼 나누는 작업을 재귀로 반복
		cout << n % 2; //나머지 차례로 출력
	}
}

void HexaDecimal(char *arr, int b2) //16진수에서 2진수로 변환
{
	char str[20] = {};
	char str1[5]={}, str2[5]={};
	switch (arr[0]) { //첫번째 자리의 값을 2진수로 치환
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
	strcat(str, str1); //새 문자열에 저장

	switch (arr[1]) { //두번째 자리의 값을 2진수로 치환
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
	strcat(str, str2); //그 전 배열에 이어 붙임
	Binary(str, b2); //2진수에서 변환하는 함수로 전달
}

int main()
{
	long n; char arr[9]; //10진법용 변수, 그 외 진법용 배열
	int b1, b2; //원래 진법, 변환할 진법
	cin >> b1 >> b2;
	if (b1 == 10) { //10진수로 받을 때에는 long형으로 받음
		cin >> n;
	}
	else { //그 외 진수로 받을 때에는 char형으로 받음
		cin >> arr;
	}

	switch (b1) {
	case 2: //원래 2진수였을 때
		Binary(arr, b2); //2진수에서 변환하는 함수 호출
		break;
	case 8: //원래 8진수였을 때
		Octal(arr, b2); //8진수에서 변환하는 함수 호출
		break;
	case 10: //원래 10진수였을 때
		Decimal(n, b2); //10진수에서 변환하는 함수 호출
		break;
	case 16: //원래 16진수였을 때
		HexaDecimal(arr, b2); //16진수에서 변환하는 함수 호출
		break;
	}
	return 0;
}