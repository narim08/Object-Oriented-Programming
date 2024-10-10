#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class SongNode //������ �뷡 ���� ���� ���� ���Ḯ��Ʈ
{
public:
	char* title; //�뷡 ����
	SongNode* pNext;

	SongNode(char* title);
	~SongNode();
};

class ArtistNode //���� �̸� ���� ���Ḯ��Ʈ
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

class MyMusicManagementList //�ؽ�Ʈ ���� �б�
{
public:
	ArtistNode* MpHead;

	MyMusicManagementList();
	~MyMusicManagementList();

	void Finput(); //���� �ҷ��ͼ� ����

	ArtistNode* getHead();
};