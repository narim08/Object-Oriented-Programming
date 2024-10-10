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

void MyMusicManagementList::Finput() { //파일 불러와서 정렬
	
	ifstream finput("Music_info.txt");

	if (!finput) { //예외 처리
		cout << "파일을 열 수 없습니다." << endl;
		exit(1);
	}

	/*처음 목록 제목 한 줄 따로 빼옴*/
	char dstr[100] = {};
	finput.getline(dstr, 100);

	/*내용 정보 저장*/
	char str[100] = {};
	while (finput.eof()) { //파일 끝 도달 전까지 반복
		char* Artist = strtok(str, "/");
		char* Songs = strtok(NULL, "\n");

		ArtistNode* pCurr = MpHead;
		ArtistNode* pPrev = nullptr;

		while (pCurr) {
			/*이름이 다르면 새로 노드 생성하여 연결*/
			if (strcmp(Artist, pCurr->artist) != 0) {
				pPrev = pCurr;
				pCurr = pCurr->pNext;
			}
		}
		/*이름이 같은 경우 하위 노드로 노래 제목 추가*/
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
	/*가수 이름 깊은 복사*/
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
		if (strcmp(pCurr->title, title) < 0) { //새 노래가 앞서는 경우 
			pPrev = pCurr; //현재값 저장
			pCurr = pCurr->pNext; //다음 노드 이동
		}
		pCurr = pCurr->pNext; //다음 노드 이동
	}
	if (pPrev == nullptr) { //앞의 if문을 안 거친 경우
		sNode->pNext = pHead;
		pHead = sNode;
	}
	else { //마지막에 저장해야 되는 경우
		sNode->pNext = pPrev->pNext;
		pPrev->pNext = sNode;
	}
}

ArtistNode* ArtistNode::getPrev() {
	ArtistNode* pPrev = getHead();
	/*원형연결리스트 탐색*/
	while (pPrev&& pPrev->pNext != this) {
		pPrev = pPrev->pNext;
	}
	return pPrev;
}




SongNode::SongNode(char* title) :pNext{ nullptr } { 
	/*곡 제목 깊은 복사*/
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

SongNode::~SongNode() {
	delete[] title;
}