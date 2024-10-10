#include "music_class.h"

int main()
{   
	char *title, *singer, *album;
	int track, year;
	int size = 0; //배열 크기

	cout << "목록 개수: ";
	cin >> size;
	myMusic* m = new myMusic[size]; //클래스 객체 배열 동적할당

	for (int i = 0; i < size; i++) {
		cout << "/* 제목, 가수, 앨범, 트랙 번호, 발매 연도 입력 */" << endl;
		char str[50] = {};
		cin >> str;

		/*콤마로 구분하여 저장*/
		title = strtok(str, ",");
		singer = strtok(NULL, ",");
		album = strtok(NULL, ",");
		track = atoi(strtok(NULL, ",")); //정수로 변환
		year = atoi(strtok(NULL, ",")); //정수로 변환

		m[i].setTitle(title);
		m[i].setSinger(singer);
		m[i].setAlbum(album);
		m[i].setTrackNo(track);
		m[i].setYear(year);

		cout << endl;
	}
	cout << endl;

	cout << "/* 출력 */" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") ";
		cout << m[i].getTitle() << " / " << m[i].getSinger() << " / " << m[i].getAlbum() << " / " << m[i].getTrackNo() << " / " << m[i].getYear() << endl;
		cout << endl;
	}
	
	delete[] m; //클래스 배열 동적할당 해제
	return 0;
}