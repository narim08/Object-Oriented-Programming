#include "merge.h"

int main()
{
	List list, list2;
	char str[100];
	cout << "Input>>" << endl;
	cout << "Input list 1: ";
	scanf("%[^\n]s", str); //�������� �Է� �ޱ�
	scanf("%*c"); //���� ���� ���� �Է� �޾Ƽ� ���� ���

	char* arr = strtok(str, " ");
	while (arr) {
		list.addNode(arr);
		arr = strtok(NULL, " ");
	}
	list.MS();
	cout << "list 1 ����: ";
	list.Print();
	cout << endl;


	char str2[100];
	cout << "Input list 2: ";
	scanf("%[^\n]s", str2); //�������� �Է� �ޱ�
	scanf("%*c"); //���� ���� ���� �Է� �޾Ƽ� ���� ���

	char* arr2 = strtok(str2, " ");
	while (arr2) {
		list2.addNode(arr2);
		arr2 = strtok(NULL, " ");
	}
	list2.MS();
	cout << "list 2 ����: ";
	list2.Print();
	cout << endl;
	cout << endl;
	
	cout << "Output>>" << endl;
	List list3;
	list3.Merge_List(list, list2);
	list3.Print();

	return 0;
}