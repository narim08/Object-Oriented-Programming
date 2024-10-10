#include "stack.h"

int main()
{
	int size;
	cout << "Stack�� ũ�� �Է�: ";
	cin >> size;
	cout << "----------------------" << endl;

	Stack s;
	s.SetSize(size); //ť ������ ����

	Node* node;

	string str;
	while (1) {
		cin >> str; int n, num = 0;
		if (str == "push") {
			node = new Node();
			cin >> n;
			node->SetData(n);
			s.Push(node);
		}
		if (str == "pop") {
			node = s.Pop();
			if (node != nullptr) {
				cout << node->GetData() << endl;
				delete node;
			}
		}
		if (str == "print") {
			s.PrintStack();
			cout << endl;
			cout << endl;
		}
		if (str == "exit") {
			break;
		}
	}
	return 0;
}