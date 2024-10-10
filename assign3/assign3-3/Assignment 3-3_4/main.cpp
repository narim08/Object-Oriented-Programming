#include "Score.h"

int main()
{
	StudentScoreList list; //리스트 객체 생성

	int n = 0; //학생 수 입력
	cout << "학생 수: "; cin >> n;
	cout << endl;

	Score* std = new Score[n]; //점수 객체 배열 동적할당


	cout << "/* 점수 입력 */" << endl;
	for (int i = 0; i < n; i++) {
		double m = 0, e = 0, s = 0; //수학, 영어, 과학 점수
		
		cout << "수학 점수: "; cin >> m;
		cout << "영어 점수: "; cin >> e;
		cout << "과학 점수: "; cin >> s;

		double avg = (m + e + s) / 3; //평균 계산
		cout << "학생" << i + 1 << "의 평균: " << avg << endl;
		cout << endl;

		std[i].SetAvg(avg); //평균 점수 설정
		list.Insert(&std[i]); //오름차순 추가
	}
	cout << endl;


	cout << "오름차순: 1 / 내림차순: 2" << endl;
	int num = 0;
	cin >> num;
	switch (num) {
	case 1:
		list.PrintList(true);
		break;
	case 2:
		list.PrintList(false);
		break;
	default:
		cout << "잘못된 번호를 입력했습니다." << endl;
	}

	delete[] std; //동적할당 해제
	return 0;
}