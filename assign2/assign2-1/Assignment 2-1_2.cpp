#include <iostream>
using namespace std;

bool emp(int t) { //스택이 비어있는지 확인하는 함수
	if (t < 0) //비어있을 시
		return true;
	else
		return false;
}

void push(int* stack, int t, int n) //스택에 삽입하는 함수
{
	stack[n] = t; //경로 값 저장(0)
}

int pop(int* stack, int* t) { //스택의 top을 삭제하는 함수
	if (!emp(*t)) { //스택이 비어있지 않으면
		return stack[(*t)--]; //top값 반환 후 인덱스 감소
	}
	else {
		cout << "스택이 비어있습니다." << endl;
		return NULL;
	}
}

void maze_path(int** maze, int sp_row, int sp_col, int dp_row, int dp_col) //미로 길 찾기 함수
{
	maze[sp_row][sp_col] = 1; //시작점을 벽으로 바꿈
	int t = 0, n = -1; //스택의 현재 위치, 이동 횟수 저장 변수
	int ROW=sp_row, COL=sp_col; //현재 행, 열 저장 변수
	int stack[128] = {}; //스택 공간

	while (1) { //출구 찾을 때까지 반복
		if (maze[ROW][COL+1]==0) { //동쪽 방향 검사
			COL++; //방향으로 이동
			t = maze[ROW][COL]; //현재 위치 값 저장
			n++; //이동 횟수 증가
			push(stack, t, n);
		}
		else if (maze[ROW+1][COL]==0) { //남쪽 방향 검사
			ROW++; //방향으로 이동
			t = maze[ROW][COL]; //현재 위치 값 저장
			n++; //이동 횟수 증가
			push(stack, t, n);
			if (ROW == dp_row) {
				break;
			}
		}
		else if (maze[ROW][COL - 1] == 0) { //서쪽 방향 검사
			COL--; //방향으로 이동
			t = maze[ROW][COL]; //현재 위치 값 저장
			n++; //이동 횟수 증가
			push(stack, t, n);
		}
		else if (maze[ROW - 1][COL - 1] == 0) { //북쪽 방향 검사
			ROW--; //방향으로 이동
			t = maze[ROW][COL]; //현재 위치 값 저장
			n++; //이동 횟수 증가
			push(stack, t, n);
		}
		else { //경로가 없을 경우 뒤로가기
			n--; //이동 횟수 감소
			pop(stack, &t);
		}
	}
	cout << n+2; //n은 -1부터 시작했으므로 +2로 해줌
	return;
}

int main()
{
	int t = -1; //top을 가리킬 포인터로 쓰일 변수
	int row, col; //행, 열
	int sp_row, sp_col, dp_row, dp_col; //시작, 끝 점의 포인트

	while (1) { //행, 열은 1~30 사이의 수만 받음
		cin >> row;
		if (row >= 1 && row <= 30) {
			cin >> col;
			if (col >= 1 && col <= 30) {
				break;
			}
		}
	}
	
	/*2차원 배열 동적할당*/
	int** maz = new int*[row+1]{}; //행의 수만큼 먼저 동적할당
	for (int i = 0; i < row+1; i++) { //열의 수만큼 메모리 이어서 동적할당
		maz[i] = new int[col+1];
	}

	/*미로 입력 받음*/
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> maz[i][j];
		}
	}
	cin >> sp_col >> sp_row >> dp_col >> dp_row;
	cout << endl;

	maze_path(maz, sp_row-1, sp_col-1, dp_row-1, dp_col-1);

	/*2차원 배열 동적할당 해제*/
	for (int i = 0; i < row+1; i++) {
		delete[] maz[i];
	}
	delete[] maz;
	return 0;
}