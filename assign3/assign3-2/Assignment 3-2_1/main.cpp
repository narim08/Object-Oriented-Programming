#include "node_class.h"

int main()
{
	Node N;
	srand(time(NULL));
	N.New_node(); 
	cout << "/* ���� ���Ḯ��Ʈ ���� */" << endl;
	N.print();
	cout << endl;


	Node* list = N.Insertion_Sort();
	cout << "/* ������������ ���Ḯ��Ʈ ����*/" << endl;
	N.print();
	cout << endl;


	cout << "/* ���Ḯ��Ʈ ���� Ž�� */" << endl;
	int n;
	cout << "�˻��� ��: ";
	cin >> n;
	Node* val = N.Binary_Search(list, n);

	if (N.search == 1) {
		cout << "�˻����: " << val->value;
	}
	else {
		cout << "�˻������ �����Ƿ� ���� ����� ���� ��ȯ�մϴ�." << endl;
		cout << "��ȯ ��: " << val->value;
	}
	cout << endl;

	return 0;
}