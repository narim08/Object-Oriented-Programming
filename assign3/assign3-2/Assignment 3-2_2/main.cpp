#include "music_class.h"

int main()
{   
	char *title, *singer, *album;
	int track, year;
	int size = 0; //�迭 ũ��

	cout << "��� ����: ";
	cin >> size;
	myMusic* m = new myMusic[size]; //Ŭ���� ��ü �迭 �����Ҵ�

	for (int i = 0; i < size; i++) {
		cout << "/* ����, ����, �ٹ�, Ʈ�� ��ȣ, �߸� ���� �Է� */" << endl;
		char str[50] = {};
		cin >> str;

		/*�޸��� �����Ͽ� ����*/
		title = strtok(str, ",");
		singer = strtok(NULL, ",");
		album = strtok(NULL, ",");
		track = atoi(strtok(NULL, ",")); //������ ��ȯ
		year = atoi(strtok(NULL, ",")); //������ ��ȯ

		m[i].setTitle(title);
		m[i].setSinger(singer);
		m[i].setAlbum(album);
		m[i].setTrackNo(track);
		m[i].setYear(year);

		cout << endl;
	}
	cout << endl;

	cout << "/* ��� */" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") ";
		cout << m[i].getTitle() << " / " << m[i].getSinger() << " / " << m[i].getAlbum() << " / " << m[i].getTrackNo() << " / " << m[i].getYear() << endl;
		cout << endl;
	}
	
	delete[] m; //Ŭ���� �迭 �����Ҵ� ����
	return 0;
}