#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Node
{
public:
	Node* pHead;
	Node* pNext;
	int value;
	bool search;

	Node();
	Node(int n);
	
	void New_node(); //랜덤 노드 생성 후 연결
	Node* Insertion_Sort(); //연결리스트 삽입 정렬

	Node* getMid(Node* l, Node* r); //연결리스트 중간 값 반환
	Node* Binary_Search(Node* p, int n); //탐색후 출력

	void print(); //연결리스트 출력
};

