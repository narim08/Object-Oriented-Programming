#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class myMusic
{
private:
	char* m_title;
	char* m_singer;
	char* m_album;
	int m_track_no;
	int m_year;

public:
	myMusic();
	~myMusic();

	void setTitle(char* title);
	void setSinger(char* singer);
	void setAlbum(char* album);
	void setYear(int year);
	void setTrackNo(int track_no);

	char* getTitle();
	char* getSinger();
	char* getAlbum();
	int getYear();
	int getTrackNo();
};