#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Node
{
public:
	char str[100];
	Node* pNext;

	Node();
};


class List
{
private:
	Node* pHead;

public:
	List();
	~List();
	void addNode(const char* str);

	Node* MergeSort(Node*s);
	Node* MidNode(Node* s);
	Node* Merge(Node* p1, Node* p2);
	void MS();

	//List& MergeSort_List(List& s);
	void Merge_List(List& p1, List& p2);
	
	void Print();
	//void Merge_List(Node* p1, Node* p2, Node* p3);
};
