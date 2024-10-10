#include "stack.h"

int main()
{
	int size;
	cout << "Stack의 크기 입력: ";
	cin >> size;
	cout << "----------------------" << endl;

	Stack s;
	s.SetSize(size); //큐 사이즈 설정

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