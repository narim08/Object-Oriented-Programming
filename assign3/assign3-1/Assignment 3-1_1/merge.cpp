#include "merge.h"

Node::Node() :str{ NULL }, pNext { nullptr }{}

List::List() : pHead{ nullptr }{}

List::~List() {
	Node* pCurr = pHead;
	while (pCurr) { //ó������ �����ؼ� �ϳ��� ����
		Node* temp = pCurr;
		pCurr = pCurr->pNext;
		delete temp;
	}
}

void List::addNode(const char* str) { //�� ��带 �����Ͽ� ���Ḯ��Ʈ�� ����� �Լ�
	Node* StrNode = new Node; //�� ��� ����
	strcpy(StrNode->str, str); //��忡 ���ڿ� ����
	StrNode->pNext = nullptr; //���� �����͸� NULL�� ����

	if (pHead == nullptr) {
		pHead = StrNode;
		return;
	}
	
	Node* pCurr = pHead;
	Node* pPrev = nullptr;

	/*���ڿ��� �����ϴ� ���¿��� �� ��� ���ڿ� ���� �� ū ���*/
	while (pCurr && strcmp(pCurr->str, StrNode->str) < 0) {
		pPrev = pCurr; //���縦 ���� �����Ϳ� ���� ��
		pCurr = pCurr->pNext; //���縦 ���� �����ͷ� ����
	}
	if (pPrev == nullptr) { //�� ��� ���� ���ų� �� ���� ��� �տ� ��ġ
		StrNode->pNext = pHead;
		pHead = StrNode;
	}
	else { //while���� �����ٸ�(�� ��� ���� ��ġ)
		StrNode->pNext = pCurr;
		pPrev->pNext = StrNode;
	}
}

/*
void List::Merge_List(Node* p1, Node* p2, Node* p3) {
	while (p1 && p2) {
		if (p1->pNext > p2->pNext) { //ù��° ���ڿ��� �� ũ��
			Node* curr = new Node(p2->str); //�ι�° ���ڿ� �ּҰ� ��� ����
			p3->pNext = curr; //����° ���ڿ��� ����
			p2 = p2->pNext; //���� ĭ���� �� ��� �ű�
		}
		else { //�ι�° ���ڿ��� �� ũ��
			Node* curr = new Node(p1->str); //ù��° ���ڿ� �ּ� ��� ����
			p3->pNext = curr; //����° ���ڿ��� ����
			p1 = p1->pNext; //���� ĭ���� �� ��� �ű�
		}
		p3 = p3->pNext;
	}


	while (1) {
		if (p2 != nullptr) { //�ι�° ���ڿ��� ���� ���
			Node* curr = new Node(p2->str); //�ι�° ���ڿ� �ּҰ� ��� ����
			p3->pNext = curr; //����° ���ڿ��� ����
			p3 = p3->pNext;
			p2 = p2->pNext;
		}
		else if (p1 != nullptr) { //ù��° ���ڿ��� ���� ���
			Node* curr = new Node(p1->str); //ù��° ���ڿ� �ּ� ��� ����
			p3->pNext = curr; //����° ���ڿ��� ����
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
	if (s == nullptr || s->pNext == nullptr) { //����ó��
		return s;
	}
	Node* mid = MidNode(s);
	Node* midNext = mid->pNext;

	mid->pNext = nullptr;
	
	/*�����Ͽ� ���ȣ�� �ݺ� ����*/
	Node* left = MergeSort(s);
	Node* right = MergeSort(midNext);

	return Merge(left, right);
}

Node* List::MidNode(Node* s) { //�������Ŀ��� ���� �߰� �� ã�� �Լ�
	if (s == nullptr) { //����ó��
		return nullptr;
	}

	Node* pPrev = s;
	Node* pCurr = s->pNext;
	while (pCurr) { //������ �˻�
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
	/*����ó�� (���� ���� ���� ���)*/
	if (p1 == nullptr)
		return p2;
	if (p2 == nullptr)
		return p1;

	if (strcmp(p1->str, p2->str) > 0) { //p1���� �� Ŭ ���
		res = p2; //���� �� �� ��忡 ����
		res->pNext = Merge(p1, p2->pNext); //�� ��� �����Ϳ� ���� ���� ���ȣ���Ͽ� ����
	}
	else { //p2���� ���ų� �� Ŭ ���
		res = p1; 
		res->pNext = Merge(p1->pNext, p2);
	}

	return res; //���� �� ���� ��� ��ȯ
}

void List::MS() {
	pHead = MergeSort(pHead);
}


/*�� ���Ḯ��Ʈ �ٽ� ����*/
/*
List& List::MergeSort_List(List& s) {
	//����ó��
	if (pHead == nullptr || pHead->pNext == nullptr) {
		return;
	}
	
	
}
*/
void List::Merge_List(List& p1, List& p2) {
	Node* Lp1 = p1.pHead;
	Node* Rp2 = p2.pHead;

	//����ó��
	if (Lp1 == nullptr) {
		pHead = Rp2;
		return;
	}
	if (Rp2 == nullptr) {
		pHead = Lp1;
		return;
	}

	if (Lp1->str > Rp2->str) { //ù��° ����Ʈ ���� �� ū ���
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
	//���� ����Ʈ ��尡 ���� ��� �̾ ����
	if (Lp1) {
		pCurr->pNext = Lp1;
	}
	else {
		pCurr->pNext = Rp2;
	}
}



void List::Print() { //�� ����ϴ� �Լ�
	Node* pCurr = pHead;
	while (pCurr) { //ó������ ������ ���
		cout << pCurr->str << ' ';
		pCurr = pCurr->pNext;
	}
	cout << endl;
}