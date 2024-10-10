#include "queue.h"

//Node 클래스 멤버함수
Node::Node() :m_pNext{ nullptr }, m_Data(0){}

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


//Queue 클래스 멤버함수
Queue::Queue():m_pHead{nullptr}, m_pTail{nullptr}, m_Size(0), m_NumElement(0) {}

Queue::~Queue() {
	if (!IsEmpty())
		delete Pop(); //노드 지울 때 메모리도 같이 해제
}

void Queue::SetSize(int n) { //큐의 크기 설정
	m_Size = n;
}

bool Queue::IsEmpty() {
	if (m_pHead == nullptr) //첫번째 칸이 비어있으면 큐 자체 빈 상태
		return true;
	else
		return false;
}

bool Queue::IsFull() {
	if (m_NumElement == m_Size) //노드 개수가 큐의 크기와 같으면 꽉 찬 상태
		return true;
	else
		return false;
}

bool Queue::Push(Node* pNode) { //삽입
	if (IsEmpty()) { //큐가 비어있으면
		m_pHead = pNode; //불러온 노드를 첫번째로 설정
		m_pTail = pNode; //마지막도 같이 첫번째로 설정
	}
	else if (IsFull()) { //공간이 더 없을 시
		cout << "큐가 가득 찼습니다." << endl;
		cout << endl;
		return false;
	}
	else {
		m_pTail->SetNext(pNode); //새로운 노드와 연결
		m_pTail = pNode; //마지막을 새로운 노드로 설정
	}

	m_NumElement++; //노드 개수 증가
	return true;
}

Node* Queue::Pop() { //삭제
	if (IsEmpty()) { //노드가 이미 없는 경우
		cout << "큐가 비어있습니다." << endl;
		cout << endl;
		return nullptr;
	}

	Node* del = m_pHead; //지울 노드에 첫번째 포인터 값으로 초기화
	m_pHead = m_pHead->GetNext(); //첫번째 포인터가 다음 노드를 가리키게 바꿈
	del->SetNext(nullptr); //노드 삭제
	
	if (IsEmpty()) { //삭제했더니 비어있는 경우
		m_pTail = nullptr; //마지막 포인터도 null포인터로 설정
	}

	m_NumElement--; //노드 개수 감소
	return del; //지운 노드 반환
}

void Queue::PrintQueue() {
	Node* cur = m_pHead; //첫번째 값부터 현재 값으로 설정
	
	while (cur) { //끝 도달 전까지 반복
		cout << cur->GetData() << ' '; //현재 값 출력
		cur = cur->GetNext(); //다음 칸 가리킴
	}
}