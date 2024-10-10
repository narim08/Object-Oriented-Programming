#include "queue.h"

int main()
{
	int size;
	cout << "Queue�� ũ�� �Է�: ";
	cin >> size;
	cout << "----------------------" << endl;

	Queue q;
	q.SetSize(size); //ť ������ ����

	Node* node;

	string str;
	while (1) {
		cin >> str; int n, num=0;
		if (str == "push") {
			node = new Node();
			cin >> n;
			node->SetData(n);
			q.Push(node);
		}
		if (str == "pop") {
			node = q.Pop();
			if (node != nullptr) {
				cout << node->GetData() << endl;
				delete node;
			}
		}
		if (str == "print") {
			q.PrintQueue();
			cout << endl;
			cout << endl;
		}
		if (str == "exit") {
			break;
		}
	}
	return 0;
}