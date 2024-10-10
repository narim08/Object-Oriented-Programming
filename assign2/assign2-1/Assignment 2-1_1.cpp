#include <iostream>
using namespace std;

bool emp(int t) { //스택이 비어있는지 확인하는 함수
	if (t < 0) //비어있을 시
		return true;
	else
		return false;
}

void empty(int t) //스택이 비어있는지 확인하고 출력하는 함수
{
	if (t < 0) //비어있을 시
		cout << '1' << endl;
	else
		cout << '0' << endl;
}

void push(int* stack, int *t) //스택에 삽입하는 함수
{
	int n;
	cin >> n;
	stack[++*t] = n; //인덱스값 증가 후 숫자 저장
}

int pop(int* stack, int *t) { //스택의 top을 출력 후 삭제하는 함수
	if (!emp(*t)) { //스택이 비어있지 않으면
		cout << stack[*t] << endl; //top 출력 후
		return stack[(*t)--]; //top값 반환 후 인덱스 감소
	}
	else {
		cout << "스택이 비어있습니다." << endl;
		return NULL; 
	}
}

void top(int* stack, int *t) { //스택의 top을 출력하는 함수
	if (!emp(*t)) { //스택이 비어있지 않으면
		cout << stack[*t] << endl; //top 출력
	}
	else
		cout << "스택이 비어있습니다." << endl;
}

void print(int* stack, int *t) { //스택의 맨 아래부터 출력하는 함수
	for (int i = 0; i <= *t; i++) {
		cout << stack[i] << ' ';
	}
	cout << endl;
}


int main()
{
	int stack[128] = {}; //스택 공간
	int t = -1; //top을 가리킬 포인터로 쓰일 변수
	char str[10]={}; //명령어 입력 받을 배열

	while (1) { //exit 입력까지 반복
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