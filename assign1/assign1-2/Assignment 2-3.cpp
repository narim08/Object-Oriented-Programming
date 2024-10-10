#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
	char fname[50]; //텍스트 파일 이름을 입력 받을 배열
	char fstr[100]; //파일 안의 내용들을 저장할 배열
	char arr1[10], arr2[50]; //찾고자 하는 문자열 입력 받을 배열
	char Arr1[10], Arr2[50]; //탐색용 배열
	int num;//찾고자 하는 파일 개수
	int n1=0, n2=0; //와일드카드 전까지의 위치를 저장할 변수
	int i = 0;


	/*사용자로부터 정보 입력 받음*/
	cout << "Input file name: ";
	cin >> fname;
	cin >> num;
	cin >> arr1;
	cin >> arr2;
	cout << endl << endl;

	ifstream finput; //읽기용 파일 스트림 객체 생성
	finput.open(fname); //입력받은 파일 오픈

	/*파일을 찾을 수 없는 경우 종료 안내문*/
	if (!finput) { 
		cout << "파일을 열 수 없습니다." << endl;
		exit(1);
	}


	/*첫번째 문자열*/
	for (i = 0; arr1[i]!='*'; i++) { //* 만나기 전까지 반복
		n1 = i;
		if (arr1[i] == NULL) { //*이 아닌 경우
			for (i = 0; arr1[i] != '?'; i++) { //? 만나기 전까지 반복
				n1 = i;
				if (arr1[i] == NULL) { //와일드 카드가 없는 경우 종료
					cout << "입력이 올바르지 않습니다." << endl;
					exit(1);
				}
			}
		} 
	}
	n1++; //와일드카드 위치로 n값 저장
	strncpy(Arr1, arr1, n1); //새로운 배열에 이름까지만 복사
	Arr1[n1] = '\0'; //원래 와일드카드 위치에 문자열 끝 알림 넣기
	

	/*두번째 문자열*/
	for (i = 0; arr2[i] != '?'; i++) { //* 만나기 전까지 반복
		n2 = i;
		if (arr2[i] == NULL) { //*이 아닌 경우
			for (i = 0; arr2[i] != '*'; i++) { //? 만나기 전까지 반복
				n2 = i;
				if (arr2[i] == NULL) { //와일드 카드가 없는 경우 종료
					cout << "입력이 올바르지 않습니다." << endl;
					exit(1);
				}
			}
		}
	}
	n2++; //와일드카드 위치로 n값 저장
	strncpy(Arr2, arr2, n2); //새로운 배열에 이름까지만 복사
	Arr2[n2] = '\0'; //원래 와일드카드 위치에 문자열 끝 알림 넣기
	

	/*문자열 검색*/
	while (!finput.eof()) { //파일의 끝에 도달하기 전까지 반복
		finput.getline(fstr, 100); //한 줄씩 불러오기
		char* ptr = strstr(fstr, Arr1); //불러온 문자열과 검색한 문자열 일치 여부 탐색
		if (ptr != NULL) { //찾으면 NULL값이 아니므로
			cout << fstr << endl; //일치한 문자열 출력
		}
	}
	finput.close();



	/*두번째 문자열 검색을 위해 파일 다시 열음*/
	ifstream finput2; //읽기용 파일 스트림 객체2 생성
	finput2.open(fname);

	while (!finput2.eof()) {
		finput2.getline(fstr, 100);
		char* ptr2 = strstr(fstr, Arr2);
		if (ptr2 != NULL) {
			cout << fstr << endl;
		}
	}
	finput2.close();

	return 0;
}