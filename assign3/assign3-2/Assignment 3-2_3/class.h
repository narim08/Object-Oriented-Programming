#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class SongNode //가수의 노래 제목 하위 원형 연결리스트
{
public:
	char* title; //노래 제목
	SongNode* pNext;

	SongNode(char* title);
	~SongNode();
};

class ArtistNode //가수 이름 원형 연결리스트
{
public:
	ArtistNode* APrev = APrev->getPrev();
	char* artist;
	ArtistNode* pNext;
	SongNode* pHead;

	ArtistNode(char* artist);
	~ArtistNode();

	void New_Song(char* title);
	ArtistNode* getPrev();
};

class MyMusicManagementList //텍스트 파일 읽기
{
public:
	ArtistNode* MpHead;

	MyMusicManagementList();
	~MyMusicManagementList();

	void Finput(); //파일 불러와서 정렬

	ArtistNode* getHead();
};