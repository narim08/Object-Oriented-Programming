#include "stack.h"

//Node 클래스 멤버함수
Node::Node():m_pNext{nullptr}, m_Data(0){}
Node::~Node(){
	m_pNext = NULL; //NULL로 설정하여 소멸
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


//Stack 클래스 멤버함수
Stack::Stack():m_pHead{nullptr}, m_Size(0), m_NumElement(0){}
Stack::~Stack(){
	if (!IsEmpty())
		delete Pop(); //노드 지울 때 메모리도 같이 해제
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
	if (m_NumElement == m_Size) //노드 개수와 스택 크기가 같으면 다 참
		return true;
	else
		return false;
}

bool Stack::Push(Node*pNode) {
	if (IsEmpty()) {
		m_pHead = pNode;
	}
	else if (IsFull()) {
		cout << "스택이 가득 차 있습니다." << endl;
		cout << endl;
		return false;
	}
	else {
		pNode->SetNext(m_pHead); //새로운 노드와 연결
		m_pHead = pNode; //현재 포인터를 다음 노드로 옮김
	}
	
	m_NumElement++; //노드 개수 증가
	return true;
}

Node* Stack::Pop() {
	if (IsEmpty()) {
		cout << "스택이 비어있습니다." << endl;
		cout << endl;
		return nullptr;
	}
	Node* del = m_pHead; //지울 노드에 현재 포인터 값 저장
	m_pHead = del->GetNext(); //다음 노드로 옮김

	m_NumElement--; //노드 개수 감소
	return del;
}

void Stack::PrintStack() {
	Node* cur = m_pHead;
	while (cur) { //끝 도달 전까지 반복
		cout << cur->GetData() << ' '; //현재 값 출력
		cur = cur->GetNext(); //다음 칸 가리킴
	}
}