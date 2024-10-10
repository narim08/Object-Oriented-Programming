#include "CSVLoader.h"
#include <iostream>


int main()
{
	char fname[20] = "CSVLoader_Data.txt";
	CSVLoader csv(fname); //파일 이름 보냄


	/*파일 오픈*/
	ifstream finput(fname);
	if (finput.fail()) { //예외 처리
		cout << "파일을 열 수 없습니다." << endl;
		exit(1);
	}

	char line[128]; //파일에서 읽어들일 배열
	int i = 0;
	float lineF[128] = {}; //실수로 변환하여 저장할 배열
	string readStr = ""; //읽은 문자열을 저장
	string STR; //총 합칠 문자열


	while (finput.getline(line, ',')) { //콤마까지 읽음
		readStr = line; //읽은 걸 string타입에 저장
		STR += readStr + "\n"; //개행과 함께 총 문자열로 저장
		/*
		lineF[i] = (float)atof(readStr.c_str());
		cout << lineF[i] << ' ';
		i++;
		if (i % 2 == 0) {
			cout << endl;
		}
		*/
	}
	
	cout << STR;

	finput.close();
	return 0;
}