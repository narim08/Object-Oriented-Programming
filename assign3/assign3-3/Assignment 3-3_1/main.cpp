#include "class.h"

int main()
{
	double p1, p2; //item1, item2�� �� ����
	char d[5]; //������

	/*���� �Է� �ޱ�*/
	cout << "==============================" << endl;
	cout << "Price Compare Program" << endl;
	cout<<"==============================" << endl;
	cout << "Insert item1 price: $"; cin >> p1;
	cout << "Insert item2 price: $"; cin >> p2;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Insert discount percent: "; cin >> d;
	cout << "------------------------------" << endl;
	cout << "Result:" << endl;
	
	double dis = atof(d); //'%'���� ���ڸ� ����

	/*item1 ���� ���� ����*/
	DiscountSale item1(p1, dis);

	/*item2 ���� ���� ����*/
	DiscountSale item2(p2, dis);

	/*���� �� �� ��� ('<'�����ڸ� ��� ����)*/
	if (item1 < item2) { //item2�� ������ �� ��� ���
		cout << "Discont price of item1 is cheaper." << endl;
		cout << "Saving discount price is $"; printf("%.1f", item2.Savings(item1));
	}
	else if (item2 < item1) { //item1�� ������ �� ��� ���
		cout << "Discont price of item2 is cheaper." << endl;
		cout << "Saving discount price is $"; printf("%.1f", item1.Savings(item2));
	}
	else { //�� ������ ������ ���
		cout << "Both item are the same price." << endl;
	}
	cout << endl;

	return 0;
}