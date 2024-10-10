#include "queue.h"

//Node Ŭ���� ����Լ�
Node::Node() :m_pNext{ nullptr }, m_Data(0){}

Node::~Node(){
	m_pNext = NULL; //NULL�� �����Ͽ� �Ҹ�
}

void Node::SetData(int n) {
	m_Data = n;
}

void Node::SetNext(Node* pNext) {
	m_pNext = pNext;
}

int Node::GetData() {
	return m_Data;
}

Node* Node::GetNext() {
	return m_pNext;
}


//Queue Ŭ���� ����Լ�
Queue::Queue():m_pHead{nullptr}, m_pTail{nullptr}, m_Size(0), m_NumElement(0) {}

Queue::~Queue() {
	if (!IsEmpty())
		delete Pop(); //��� ���� �� �޸𸮵� ���� ����
}

void Queue::SetSize(int n) { //ť�� ũ�� ����
	m_Size = n;
}

bool Queue::IsEmpty() {
	if (m_pHead == nullptr) //ù��° ĭ�� ��������� ť ��ü �� ����
		return true;
	else
		return false;
}

bool Queue::IsFull() {
	if (m_NumElement == m_Size) //��� ������ ť�� ũ��� ������ �� �� ����
		return true;
	else
		return false;
}

bool Queue::Push(Node* pNode) { //����
	if (IsEmpty()) { //ť�� ���������
		m_pHead = pNode; //�ҷ��� ��带 ù��°�� ����
		m_pTail = pNode; //�������� ���� ù��°�� ����
	}
	else if (IsFull()) { //������ �� ���� ��
		cout << "ť�� ���� á���ϴ�." << endl;
		cout << endl;
		return false;
	}
	else {
		m_pTail->SetNext(pNode); //���ο� ���� ����
		m_pTail = pNode; //�������� ���ο� ���� ����
	}

	m_NumElement++; //��� ���� ����
	return true;
}

Node* Queue::Pop() { //����
	if (IsEmpty()) { //��尡 �̹� ���� ���
		cout << "ť�� ����ֽ��ϴ�." << endl;
		cout << endl;
		return nullptr;
	}

	Node* del = m_pHead; //���� ��忡 ù��° ������ ������ �ʱ�ȭ
	m_pHead = m_pHead->GetNext(); //ù��° �����Ͱ� ���� ��带 ����Ű�� �ٲ�
	del->SetNext(nullptr); //��� ����
	
	if (IsEmpty()) { //�����ߴ��� ����ִ� ���
		m_pTail = nullptr; //������ �����͵� null�����ͷ� ����
	}

	m_NumElement--; //��� ���� ����
	return del; //���� ��� ��ȯ
}

void Queue::PrintQueue() {
	Node* cur = m_pHead; //ù��° ������ ���� ������ ����
	
	while (cur) { //�� ���� ������ �ݺ�
		cout << cur->GetData() << ' '; //���� �� ���
		cur = cur->GetNext(); //���� ĭ ����Ŵ
	}
}