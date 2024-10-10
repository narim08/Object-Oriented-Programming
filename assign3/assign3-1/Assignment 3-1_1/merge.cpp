#include "merge.h"

Node::Node() :str{ NULL }, pNext { nullptr }{}

List::List() : pHead{ nullptr }{}

List::~List() {
	Node* pCurr = pHead;
	while (pCurr) { //처음부터 시작해서 하나씩 지움
		Node* temp = pCurr;
		pCurr = pCurr->pNext;
		delete temp;
	}
}

void List::addNode(const char* str) { //새 노드를 생성하여 연결리스트로 만드는 함수
	Node* StrNode = new Node; //새 노드 생성
	strcpy(StrNode->str, str); //노드에 문자열 복사
	StrNode->pNext = nullptr; //다음 포인터를 NULL로 설정

	if (pHead == nullptr) {
		pHead = StrNode;
		return;
	}
	
	Node* pCurr = pHead;
	Node* pPrev = nullptr;

	/*문자열이 존재하는 상태에서 새 노드 문자열 값이 더 큰 경우*/
	while (pCurr && strcmp(pCurr->str, StrNode->str) < 0) {
		pPrev = pCurr; //현재를 이전 포인터에 저장 후
		pCurr = pCurr->pNext; //현재를 다음 포인터로 설정
	}
	if (pPrev == nullptr) { //새 노드 값이 같거나 더 작은 경우 앞에 배치
		StrNode->pNext = pHead;
		pHead = StrNode;
	}
	else { //while문에 들어갔었다면(새 노드 끝에 배치)
		StrNode->pNext = pCurr;
		pPrev->pNext = StrNode;
	}
}

/*
void List::Merge_List(Node* p1, Node* p2, Node* p3) {
	while (p1 && p2) {
		if (p1->pNext > p2->pNext) { //첫번째 문자열이 더 크면
			Node* curr = new Node(p2->str); //두번째 문자열 주소값 노드 생성
			p3->pNext = curr; //세번째 문자열에 저장
			p2 = p2->pNext; //다음 칸으로 비교 대상 옮김
		}
		else { //두번째 문자열이 더 크면
			Node* curr = new Node(p1->str); //첫번째 문자열 주소 노드 생성
			p3->pNext = curr; //세번째 문자열에 저장
			p1 = p1->pNext; //다음 칸으로 비교 대상 옮김
		}
		p3 = p3->pNext;
	}


	while (1) {
		if (p2 != nullptr) { //두번째 문자열이 남은 경우
			Node* curr = new Node(p2->str); //두번째 문자열 주소값 노드 생성
			p3->pNext = curr; //세번째 문자열에 저장
			p3 = p3->pNext;
			p2 = p2->pNext;
		}
		else if (p1 != nullptr) { //첫번째 문자열이 남은 경우
			Node* curr = new Node(p1->str); //첫번째 문자열 주소 노드 생성
			p3->pNext = curr; //세번째 문자열에 저장
			p3 = p3->pNext;
			p1 = p1->pNext;
		}
		else {
			p3->pNext = nullptr;
			break;
		}
	}
}
*/

Node* List::MergeSort(Node* s) {
	if (s == nullptr || s->pNext == nullptr) { //예외처리
		return s;
	}
	Node* mid = MidNode(s);
	Node* midNext = mid->pNext;

	mid->pNext = nullptr;
	
	/*분할하여 재귀호출 반복 저장*/
	Node* left = MergeSort(s);
	Node* right = MergeSort(midNext);

	return Merge(left, right);
}

Node* List::MidNode(Node* s) { //병합정렬에서 기준 중간 값 찾는 함수
	if (s == nullptr) { //예외처리
		return nullptr;
	}

	Node* pPrev = s;
	Node* pCurr = s->pNext;
	while (pCurr) { //끝까지 검사
		pCurr = pCurr->pNext;
		if (pCurr) {
			pPrev = pPrev->pNext;
			pCurr = pCurr->pNext;
		}
	}
	return pPrev;
}

Node* List::Merge(Node* p1, Node* p2) {
	Node* res = nullptr;
	/*예외처리 (한쪽 값만 있을 경우)*/
	if (p1 == nullptr)
		return p2;
	if (p2 == nullptr)
		return p1;

	if (strcmp(p1->str, p2->str) > 0) { //p1값이 더 클 경우
		res = p2; //작은 값 새 노드에 저장
		res->pNext = Merge(p1, p2->pNext); //새 노드 포인터에 병합 정렬 재귀호출하여 저장
	}
	else { //p2값이 같거나 더 클 경우
		res = p1; 
		res->pNext = Merge(p1->pNext, p2);
	}

	return res; //정렬 다 끝난 경우 반환
}

void List::MS() {
	pHead = MergeSort(pHead);
}


/*두 연결리스트 다시 정렬*/
/*
List& List::MergeSort_List(List& s) {
	//예외처리
	if (pHead == nullptr || pHead->pNext == nullptr) {
		return;
	}
	
	
}
*/
void List::Merge_List(List& p1, List& p2) {
	Node* Lp1 = p1.pHead;
	Node* Rp2 = p2.pHead;

	//예외처리
	if (Lp1 == nullptr) {
		pHead = Rp2;
		return;
	}
	if (Rp2 == nullptr) {
		pHead = Lp1;
		return;
	}

	if (Lp1->str > Rp2->str) { //첫번째 리스트 값이 더 큰 경우
		pHead = Rp2;
		Rp2 = Rp2->pNext;
	}
	else {
		pHead = Lp1;
		Lp1 = Lp1->pNext;
	}

	Node* pCurr = pHead;
	while (Lp1 && Rp2) {
		if (Lp1->str > Rp2->str) {
			pCurr->pNext = Rp2;
			Rp2 = Rp2->pNext;
		}
		else {
			pCurr->pNext = Lp1;
			Lp1 = Lp1->pNext;
		}
		pCurr = pCurr->pNext;
	}
	//한쪽 리스트 노드가 남은 경우 이어서 저장
	if (Lp1) {
		pCurr->pNext = Lp1;
	}
	else {
		pCurr->pNext = Rp2;
	}
}



void List::Print() { //총 출력하는 함수
	Node* pCurr = pHead;
	while (pCurr) { //처음부터 끝까지 출력
		cout << pCurr->str << ' ';
		pCurr = pCurr->pNext;
	}
	cout << endl;
}