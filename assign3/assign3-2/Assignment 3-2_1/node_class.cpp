#include "node_class.h"

Node::Node() :value(0), pHead{ nullptr }, pNext{ nullptr }, search(0){}
Node::Node(int n) : value(n), pHead{ nullptr }, pNext{ nullptr }, search(0){}


/*랜덤 노드 생성 후 연결*/
void Node::New_node() { 
	int n;
	for (int i = 0; i < 16; i++) {
		n = rand() % 201; //0~200사이 랜덤 수 저장
		Node* node = new Node(n); //해당 값을 가지는 새 노드 생성
		node->pNext = pHead; //리스트로 연결
		pHead = node;
	}
}

/*연결리스트 내림차순 삽입정렬*/
Node* Node::Insertion_Sort() { 
	/*예외처리*/
	if (pHead == nullptr || pHead->pNext == nullptr) {
		return nullptr;
	}

	Node* list = nullptr; //정렬 리스트 저장
	Node* pCurr = pHead;
	while (pCurr) {
		Node* Nnode = pCurr->pNext; //다음 값의 노드 생성
		if (list == nullptr) {
			pCurr->pNext = list;
			list = pCurr;
		}
		else if (pCurr->value > list->value) {
			pCurr->pNext = list;
			list = pCurr;
		}
		else {
			Node* plist = list;
			while (plist) {
				if (plist->pNext == nullptr || plist->pNext->value < pCurr->value) {
					pCurr->pNext = plist->pNext;
					plist->pNext = pCurr;
					break;
				}
				plist = plist->pNext;
			}
		}
		pCurr = Nnode;
	}
	pHead = list;
	return pHead;
}

/*연결리스트 중간 값 찾기*/
Node* Node::getMid(Node* l, Node* r) {
	Node* pCurr = l;
	Node* pPrev = l;
	while (pCurr == r && pCurr->pNext == r) {
		pPrev = pPrev->pNext;
		pCurr = pCurr->pNext->pNext;
	}
	return pPrev;
}

/*연결리스트 탐색*/
Node* Node::Binary_Search(Node* p, int n) {
	/*예외 처리*/
	if (p == nullptr) { //연결리스트가 비어있는 경우
		return nullptr;
	}
	Insertion_Sort(); //우선 연결리스트 정렬

	int dif = abs(p->value - n); //차이값 저장
	Node* res = pHead; //탐색실패시 가까운 값 저장

	/*연결리스트 마지막 값 찾기*/
	Node* pTail = p;
	while (pTail->pNext) {
		pTail = pTail->pNext;
	}

	/*탐색*/
	Node* l = p; //왼쪽 탐색 포인터 (처음으로 설정)
	Node* r = pTail; //오른쪽 탐색 포인터 (마지막으로 설정)

	while (l != r && r->pNext != l) { //둘이 다른 값을 가리키는 동안 반복
		Node* mid = getMid(l, r); //중간 노드 설정
		
		int mdif = abs(mid->value - n); //중간값으로부터의 차이값 저장
		if (mdif < dif) { //중간값과의 차이와 시작값과의 차이값 비교하여 더 가까운 걸 저장
			dif = mdif;
			res = getMid(l, r);
		}

		if(mid->value < n) { //중간 값보다 큰 경우 오른쪽 포인터까지 잘라서 재탐색
			r = mid;
		}
		else if (mid->value > n) { //중간 값보다 작은 경우 다음 값부터 왼쪽으로 설정하여 재탐색
			l = mid->pNext;
		}
		else { //중간 값과 일치하는 경우 반환
			search = 1;
			return mid;
		}
	}

	/*탐색 실패한 경우*/
	search = 0;
	if (abs((l->value - n) > dif)) { 
		res =  l;
	}
	if (abs(r->value - n) < dif) {
		res =  r;
	}
	return res;
}

/*연결리스트 총 출력*/
void Node::print() {
	Node* pCurr = pHead;
	while (pCurr) {
		cout << pCurr->value << ' ';
		pCurr = pCurr->pNext;
	}
	cout << endl;
}