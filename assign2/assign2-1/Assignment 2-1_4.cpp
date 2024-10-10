#include <iostream>
#include <fstream>
using namespace std;

class Txt //알파벳 배열 저장할 클래스
{
public:
	char ar[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
};


int main()
{
	Txt arr; //클래스 객체 생성
	char str[60]={}; //파일에서 읽어 온 문자열을 저장할 배열
	char ostr[30] = {}; //알파벳으로 변환한 문자열을 저장할 배열
	int n = 0, i, j, p = 0, k = 0; //문자 개수 저장할 변수, 반복문 변수들 

	ifstream finput("binary.txt"); //읽기용 파일 오픈
	ofstream foutput("alphabet.txt"); //쓰기용 파일 오픈

	/*읽기용 파일 예외처리*/
	if (!finput) {
		cout << "파일을 열 수 없습니다.";
		exit(1);
	}

	/*파일 읽어와서 저장*/
	while (!finput.eof()) { 
		finput.getline(str, 60); 
	}

	/*바이너리 문자를 알파벳으로 변환*/
	while (1)
	{
		for (i = p; str[i] != '1'; i++) { //1 만나기 전까지
			n++;
		}
		ostr[k++] = arr.ar[n];
		p = i+1;
		n = 0;
		if (str[p]==NULL) {
			break;
		}
	}
	foutput.write(ostr, k); //파일에 쓰기

	/*파일 닫기*/
	finput.close();
	foutput.close();

	return 0;
}