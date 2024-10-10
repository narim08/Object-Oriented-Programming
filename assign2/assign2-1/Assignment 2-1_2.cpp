#include <iostream>
using namespace std;

bool emp(int t) { //������ ����ִ��� Ȯ���ϴ� �Լ�
	if (t < 0) //������� ��
		return true;
	else
		return false;
}

void push(int* stack, int t, int n) //���ÿ� �����ϴ� �Լ�
{
	stack[n] = t; //��� �� ����(0)
}

int pop(int* stack, int* t) { //������ top�� �����ϴ� �Լ�
	if (!emp(*t)) { //������ ������� ������
		return stack[(*t)--]; //top�� ��ȯ �� �ε��� ����
	}
	else {
		cout << "������ ����ֽ��ϴ�." << endl;
		return NULL;
	}
}

void maze_path(int** maze, int sp_row, int sp_col, int dp_row, int dp_col) //�̷� �� ã�� �Լ�
{
	maze[sp_row][sp_col] = 1; //�������� ������ �ٲ�
	int t = 0, n = -1; //������ ���� ��ġ, �̵� Ƚ�� ���� ����
	int ROW=sp_row, COL=sp_col; //���� ��, �� ���� ����
	int stack[128] = {}; //���� ����

	while (1) { //�ⱸ ã�� ������ �ݺ�
		if (maze[ROW][COL+1]==0) { //���� ���� �˻�
			COL++; //�������� �̵�
			t = maze[ROW][COL]; //���� ��ġ �� ����
			n++; //�̵� Ƚ�� ����
			push(stack, t, n);
		}
		else if (maze[ROW+1][COL]==0) { //���� ���� �˻�
			ROW++; //�������� �̵�
			t = maze[ROW][COL]; //���� ��ġ �� ����
			n++; //�̵� Ƚ�� ����
			push(stack, t, n);
			if (ROW == dp_row) {
				break;
			}
		}
		else if (maze[ROW][COL - 1] == 0) { //���� ���� �˻�
			COL--; //�������� �̵�
			t = maze[ROW][COL]; //���� ��ġ �� ����
			n++; //�̵� Ƚ�� ����
			push(stack, t, n);
		}
		else if (maze[ROW - 1][COL - 1] == 0) { //���� ���� �˻�
			ROW--; //�������� �̵�
			t = maze[ROW][COL]; //���� ��ġ �� ����
			n++; //�̵� Ƚ�� ����
			push(stack, t, n);
		}
		else { //��ΰ� ���� ��� �ڷΰ���
			n--; //�̵� Ƚ�� ����
			pop(stack, &t);
		}
	}
	cout << n+2; //n�� -1���� ���������Ƿ� +2�� ����
	return;
}

int main()
{
	int t = -1; //top�� ����ų �����ͷ� ���� ����
	int row, col; //��, ��
	int sp_row, sp_col, dp_row, dp_col; //����, �� ���� ����Ʈ

	while (1) { //��, ���� 1~30 ������ ���� ����
		cin >> row;
		if (row >= 1 && row <= 30) {
			cin >> col;
			if (col >= 1 && col <= 30) {
				break;
			}
		}
	}
	
	/*2���� �迭 �����Ҵ�*/
	int** maz = new int*[row+1]{}; //���� ����ŭ ���� �����Ҵ�
	for (int i = 0; i < row+1; i++) { //���� ����ŭ �޸� �̾ �����Ҵ�
		maz[i] = new int[col+1];
	}

	/*�̷� �Է� ����*/
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> maz[i][j];
		}
	}
	cin >> sp_col >> sp_row >> dp_col >> dp_row;
	cout << endl;

	maze_path(maz, sp_row-1, sp_col-1, dp_row-1, dp_col-1);

	/*2���� �迭 �����Ҵ� ����*/
	for (int i = 0; i < row+1; i++) {
		delete[] maz[i];
	}
	delete[] maz;
	return 0;
}