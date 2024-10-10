#include "node_class.h"

Node::Node() :value(0), pHead{ nullptr }, pNext{ nullptr }, search(0){}
Node::Node(int n) : value(n), pHead{ nullptr }, pNext{ nullptr }, search(0){}


/*���� ��� ���� �� ����*/
void Node::New_node() { 
	int n;
	for (int i = 0; i < 16; i++) {
		n = rand() % 201; //0~200���� ���� �� ����
		Node* node = new Node(n); //�ش� ���� ������ �� ��� ����
		node->pNext = pHead; //����Ʈ�� ����
		pHead = node;
	}
}

/*���Ḯ��Ʈ �������� ��������*/
Node* Node::Insertion_Sort() { 
	/*����ó��*/
	if (pHead == nullptr || pHead->pNext == nullptr) {
		return nullptr;
	}

	Node* list = nullptr; //���� ����Ʈ ����
	Node* pCurr = pHead;
	while (pCurr) {
		Node* Nnode = pCurr->pNext; //���� ���� ��� ����
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

/*���Ḯ��Ʈ �߰� �� ã��*/
Node* Node::getMid(Node* l, Node* r) {
	Node* pCurr = l;
	Node* pPrev = l;
	while (pCurr == r && pCurr->pNext == r) {
		pPrev = pPrev->pNext;
		pCurr = pCurr->pNext->pNext;
	}
	return pPrev;
}

/*���Ḯ��Ʈ Ž��*/
Node* Node::Binary_Search(Node* p, int n) {
	/*���� ó��*/
	if (p == nullptr) { //���Ḯ��Ʈ�� ����ִ� ���
		return nullptr;
	}
	Insertion_Sort(); //�켱 ���Ḯ��Ʈ ����

	int dif = abs(p->value - n); //���̰� ����
	Node* res = pHead; //Ž�����н� ����� �� ����

	/*���Ḯ��Ʈ ������ �� ã��*/
	Node* pTail = p;
	while (pTail->pNext) {
		pTail = pTail->pNext;
	}

	/*Ž��*/
	Node* l = p; //���� Ž�� ������ (ó������ ����)
	Node* r = pTail; //������ Ž�� ������ (���������� ����)

	while (l != r && r->pNext != l) { //���� �ٸ� ���� ����Ű�� ���� �ݺ�
		Node* mid = getMid(l, r); //�߰� ��� ����
		
		int mdif = abs(mid->value - n); //�߰������κ����� ���̰� ����
		if (mdif < dif) { //�߰������� ���̿� ���۰����� ���̰� ���Ͽ� �� ����� �� ����
			dif = mdif;
			res = getMid(l, r);
		}

		if(mid->value < n) { //�߰� ������ ū ��� ������ �����ͱ��� �߶� ��Ž��
			r = mid;
		}
		else if (mid->value > n) { //�߰� ������ ���� ��� ���� ������ �������� �����Ͽ� ��Ž��
			l = mid->pNext;
		}
		else { //�߰� ���� ��ġ�ϴ� ��� ��ȯ
			search = 1;
			return mid;
		}
	}

	/*Ž�� ������ ���*/
	search = 0;
	if (abs((l->value - n) > dif)) { 
		res =  l;
	}
	if (abs(r->value - n) < dif) {
		res =  r;
	}
	return res;
}

/*���Ḯ��Ʈ �� ���*/
void Node::print() {
	Node* pCurr = pHead;
	while (pCurr) {
		cout << pCurr->value << ' ';
		pCurr = pCurr->pNext;
	}
	cout << endl;
}