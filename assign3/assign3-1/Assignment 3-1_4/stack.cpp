#include "stack.h"

//Node Ŭ���� ����Լ�
Node::Node():m_pNext{nullptr}, m_Data(0){}
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


//Stack Ŭ���� ����Լ�
Stack::Stack():m_pHead{nullptr}, m_Size(0), m_NumElement(0){}
Stack::~Stack(){
	if (!IsEmpty())
		delete Pop(); //��� ���� �� �޸𸮵� ���� ����
}

void Stack::SetSize(int n) {
	m_Size = n;
}

bool Stack::IsEmpty() {
	if (m_pHead == nullptr) 
		return true;
	else
		return false;
}

bool Stack::IsFull() {
	if (m_NumElement == m_Size) //��� ������ ���� ũ�Ⱑ ������ �� ��
		return true;
	else
		return false;
}

bool Stack::Push(Node*pNode) {
	if (IsEmpty()) {
		m_pHead = pNode;
	}
	else if (IsFull()) {
		cout << "������ ���� �� �ֽ��ϴ�." << endl;
		cout << endl;
		return false;
	}
	else {
		pNode->SetNext(m_pHead); //���ο� ���� ����
		m_pHead = pNode; //���� �����͸� ���� ���� �ű�
	}
	
	m_NumElement++; //��� ���� ����
	return true;
}

Node* Stack::Pop() {
	if (IsEmpty()) {
		cout << "������ ����ֽ��ϴ�." << endl;
		cout << endl;
		return nullptr;
	}
	Node* del = m_pHead; //���� ��忡 ���� ������ �� ����
	m_pHead = del->GetNext(); //���� ���� �ű�

	m_NumElement--; //��� ���� ����
	return del;
}

void Stack::PrintStack() {
	Node* cur = m_pHead;
	while (cur) { //�� ���� ������ �ݺ�
		cout << cur->GetData() << ' '; //���� �� ���
		cur = cur->GetNext(); //���� ĭ ����Ŵ
	}
}