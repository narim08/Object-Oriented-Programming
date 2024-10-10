#include "node_class.h"

int main()
{
	Node N;
	srand(time(NULL));
	N.New_node(); 
	cout << "/* 랜덤 연결리스트 생성 */" << endl;
	N.print();
	cout << endl;


	Node* list = N.Insertion_Sort();
	cout << "/* 내림차순으로 연결리스트 정렬*/" << endl;
	N.print();
	cout << endl;


	cout << "/* 연결리스트 이진 탐색 */" << endl;
	int n;
	cout << "검색할 값: ";
	cin >> n;
	Node* val = N.Binary_Search(list, n);

	if (N.search == 1) {
		cout << "검색결과: " << val->value;
	}
	else {
		cout << "검색결과가 없으므로 가장 가까운 값을 반환합니다." << endl;
		cout << "반환 값: " << val->value;
	}
	cout << endl;

	return 0;
}