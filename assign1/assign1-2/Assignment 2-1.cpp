#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char c1[50]={}; //첫번째 수 배열
	char c2[50]={}; //두번째 수 배열
	int i = 0, j = 0;
	int count[50] = {}; //개수 셀 배열
	
	cin >> c1 >> c2; //사용자로부터 차례대로 입력받음

	/*첫번째 숫자 개수 계산*/
	for (i = 0; c1[i] != NULL; i++) { //배열 끝 전까지 반복
		for (j = '0'; j <= '9'; j++) { //아스키코드값으로 반복
			if (c1[i] == j) { //문자 값이 일치할 시
				count[j - '0']++; //아스키코드값을 뺀 인덱스 값으로 저장
			}
		}
	}

	/*두번째 숫자 개수 계산*/
	for (i = 0; c2[i] != NULL; i++) { //위와 동일
		for (j = '0'; j <= '9'; j++) {
			if (c2[i] == j) {
				count[j - '0']++;
			}
		}
	}

	/*총 출력*/

	for (i = 0; c1[i] != NULL; i++) { 
		for (j = '0'; j <= '9'; j++) {
			if (c1[i] == j) {
				cout << c1[i] << count[j - '0'];
			}
		}
	}
	for (i = 0; c2[i] != NULL; i++) {
		for (j = '0'; j <= '9'; j++) {
			if (c2[i] == j) {
				if (c1[0] != c2[i] && c1[1] != c2[i]) { //중복 제외 출력
					cout << c2[i] << count[j - '0'];
				}
			}
		}
	}
}


/* 배열을 하나로 합쳐서 중복 검사하는 방법
strcat(c1, c2); //하나의 문자열로 이어 붙이기

for (i = 0; c1[i] != NULL; i++) { //숫자 개수 세기
	for (j = '0'; j <= '9'; j++) {
		if (c1[i] == j) {
			count[j - '0']++;
		}
	}
}


for (i = n; c1[i] != NULL; i++) { //새로운 배열 str에 중복이 아닌 문자들만 넣기
	while (i >= 1) {
		if (c1[i - 1] != c1[n]) {
			str[i] = c1[n];
			i--;
		}
	}
	n++;
}
*/