#include "class.h"

MyMusicManagementList::MyMusicManagementList():MpHead{nullptr}{}

MyMusicManagementList::~MyMusicManagementList() {
	ArtistNode* pCurr = MpHead;
	while (pCurr) {
		ArtistNode* Nnode = pCurr->pNext;
		delete[] pCurr;
		pCurr = Nnode;
	}
}

void MyMusicManagementList::Finput() { //���� �ҷ��ͼ� ����
	
	ifstream finput("Music_info.txt");

	if (!finput) { //���� ó��
		cout << "������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	/*ó�� ��� ���� �� �� ���� ����*/
	char dstr[100] = {};
	finput.getline(dstr, 100);

	/*���� ���� ����*/
	char str[100] = {};
	while (finput.eof()) { //���� �� ���� ������ �ݺ�
		char* Artist = strtok(str, "/");
		char* Songs = strtok(NULL, "\n");

		ArtistNode* pCurr = MpHead;
		ArtistNode* pPrev = nullptr;

		while (pCurr) {
			/*�̸��� �ٸ��� ���� ��� �����Ͽ� ����*/
			if (strcmp(Artist, pCurr->artist) != 0) {
				pPrev = pCurr;
				pCurr = pCurr->pNext;
			}
		}
		/*�̸��� ���� ��� ���� ���� �뷡 ���� �߰�*/
		if (strcmp(Artist, pCurr->artist) == 0 && pCurr) {
			pCurr->New_Song(Songs);
		}
		else if (strcmp(Artist, pPrev->artist) == 0 && pPrev) {
			pPrev->New_Song(Songs);
		}
		else {
			ArtistNode* artNode = new ArtistNode(Artist);
			artNode->New_Song(Songs);
			if (pPrev) {
				artNode->pNext = pPrev->pNext;
				pPrev->pNext = artNode;
				
				artNode->APrev = pPrev;
				artNode->pNext->APrev = artNode;
			}
			else {
				artNode->pNext = MpHead;
				MpHead = artNode;
				artNode->pNext->APrev = artNode;
			}
		}
	}
	finput.close();
}

ArtistNode* MyMusicManagementList::getHead() {
	return MpHead;
}

ArtistNode::ArtistNode(char* artist) : pNext{ nullptr }, pHead{ nullptr } {
	/*���� �̸� ���� ����*/
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);
}

ArtistNode::~ArtistNode() {
	delete[] artist;
}

void ArtistNode::New_Song(char* title) {
	SongNode* sNode = new SongNode(title);
	SongNode* pPrev = nullptr;
	SongNode* pCurr = pHead;
	
	while (pCurr) {
		if (strcmp(pCurr->title, title) < 0) { //�� �뷡�� �ռ��� ��� 
			pPrev = pCurr; //���簪 ����
			pCurr = pCurr->pNext; //���� ��� �̵�
		}
		pCurr = pCurr->pNext; //���� ��� �̵�
	}
	if (pPrev == nullptr) { //���� if���� �� ��ģ ���
		sNode->pNext = pHead;
		pHead = sNode;
	}
	else { //�������� �����ؾ� �Ǵ� ���
		sNode->pNext = pPrev->pNext;
		pPrev->pNext = sNode;
	}
}

ArtistNode* ArtistNode::getPrev() {
	ArtistNode* pPrev = getHead();
	/*�������Ḯ��Ʈ Ž��*/
	while (pPrev&& pPrev->pNext != this) {
		pPrev = pPrev->pNext;
	}
	return pPrev;
}




SongNode::SongNode(char* title) :pNext{ nullptr } { 
	/*�� ���� ���� ����*/
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

SongNode::~SongNode() {
	delete[] title;
}