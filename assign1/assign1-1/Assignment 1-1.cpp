#include <iostream>
#include <cmath>
using namespace std;
void Triangle(int n);

int main()
{
	int k, N; 

	while (1) { //제대로 된 범위의 값을 입력받을 때까지 반복
		cout << "Input k: ";
		cin >> k;
		if (1 <= k && k <= 8)
			break;
	}
	
	N = 3 * (int)pow(2, k - 1); //N값 계산

	Triangle(N); //함수로 전달
	
	return 0;
}

void Triangle(int n) //시에르핀스키 삼각형 구현할 함수
{
	/*기본 삼각형 배열 저장*/
	char tri[3][6] = { "  $  ", 
					   " $ $ ",
					   "$$$$$" };

	/*전달받은 N값에 따라 출력*/
	for (int a = 0; a < (n / 2) - 2; a++){
		cout << " ";
	}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				cout << tri[i][j];
			}
			cout << endl;
		}
		cout << endl;
}