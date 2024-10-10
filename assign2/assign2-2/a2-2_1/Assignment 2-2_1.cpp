#include <iostream>
using namespace std;

int main()
{
	int i = 0, j = 0, k = 0;
	char Arr[100]={}; //입력 받을 전체 배열
	char str[100] = {}; //중첩 배열 분리 저장
	char sstr[10] = {}; //중첩 배열 안 배열 요소 저장
	char ex[5] = "exit"; //종료 문자열


	scanf_s("%[^\n]s", Arr, 100);//공백포함 입력받기

	/*중첩 배열 따로 저장*/
	for (i = 1; Arr[i] != NULL; i++) { //전체 문자열 검사
		if (Arr[i] == '[') { //대괄호 시작 다음 부터 중첩 배열 저장
			for (i = i + 1; Arr[i] != ']'; i++) {
				str[j++] = Arr[i];
			}
		}
	}

	while (1) { //exit 입력 전까지 반복
		char idx = 'x'; //출력 배열 인덱스 값 x로 초기화
		char arr[10] = {}; //출력할 배열 요소 저장
		cin >> arr;

		/*출력할 인덱스 값 찾기*/
		for (i = 0; arr[i] != NULL; i++) {
			if (arr[i] == '[') {
				idx = arr[i + 1]; //대괄호 다음 인덱스 숫자 저장 
			}
		}

		/*출력*/
		if (idx == '3') { //중첩 배열 위치일 경우
			cout << '[' << str << ']' << endl;
			cout << endl;
		}
		else if (idx == '1') { //이중 중첩 배열 위치일 경우
			for (i = 0; str[i] != NULL; i++) { //문자열 끝까지 검사해서
				if (str[i] == ',') { //콤마 위치 찾으면
					for (i = i + 2; str[i] != NULL; i++) { //그 다음 문자열 저장
						sstr[k++] = str[i];
					}
				}
			}
			cout << sstr << endl;
			cout << endl;
		}
		else if (strcmp(arr, ex)==0) { //프로그램 종료시
			exit(1);
		}
		else { //인덱스 지정 안 한 경우 배열 전체 출력
			cout << Arr << endl;
			cout << endl;
		}
	}
	
	return 0;
}