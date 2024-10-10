#include <iostream>
using namespace std;

char* my_strtok(char* str) {
	static char* ptr; //문자열 주소 가리킬 포인터 정적으로 선언

	if (str != NULL) { //빈 문자열이 아니면 포인터에 저장
		ptr = str;
	}
	/*예외 처리*/
	else { 
		str = ptr;
	}
	if (*ptr == NULL) { 
		return NULL;
	}

	char* tok = ptr; //ptr은 static이므로 함수 재호출 시 이전 문자열 다음 위치 저장
	while (*ptr) {
		if (*ptr == '@' || *ptr == '.') { //특정 문자일 경우
			*ptr = NULL; //NULL로 치환
			++ptr; //다음 문자로 이동
			return tok; //해당 문자열 주소 반환
		}
		++ptr;
	}
	return tok; //다 자른 경우
}


int main()
{
	char str[50]={}; //이메일 입력 받을 배열
	cin >> str;
	
	/*첫번째로 자른 문자열 출력*/
	cout << my_strtok(str) << endl;

	/*두번째부터는 이전 호출 이후부터 다시 검사*/
	char* temp2 = my_strtok(NULL);
	while (temp2) { //문자열 끝까지 반복
		cout << temp2 << endl;
		temp2 = my_strtok(NULL);
	}
	return 0;
}