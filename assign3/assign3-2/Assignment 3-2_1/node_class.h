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
	
	void New_node(); //���� ��� ���� �� ����
	Node* Insertion_Sort(); //���Ḯ��Ʈ ���� ����

	Node* getMid(Node* l, Node* r); //���Ḯ��Ʈ �߰� �� ��ȯ
	Node* Binary_Search(Node* p, int n); //Ž���� ���

	void print(); //���Ḯ��Ʈ ���
};

