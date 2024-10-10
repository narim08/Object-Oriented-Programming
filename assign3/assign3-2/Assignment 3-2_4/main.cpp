#include "class.h"

int main()
{
	/*ù��° ���׽� ���� ����*/
	Polynomial p1;
	int n, e, c;
	
	cout << "ù��° ���׽��� �� ����: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		Term* pNew = new Term();
		cout << "���: "; cin >> c; pNew->SetCoeff(c);
		cout << "����: "; cin >> e; pNew->SetExponent(e);
		p1.Insert(pNew);
	}
	cout << endl;
	cout << "ù��° ���׽�: ";
	p1.PrintList();
	cout << endl;
	cout << endl;


	/*�ι�° ���׽� ���� ����*/
	Polynomial p2;
	int n2, e2, c2;

	cout << "�ι�° ���׽��� �� ����: ";
	cin >> n2;

	for (int i = 0; i < n2; i++) {
		Term* pNew = new Term();
		cout << "���: "; cin >> c2; pNew->SetCoeff(c2);
		cout << "����: "; cin >> e2; pNew->SetExponent(e2);
		p2.Insert(pNew);
	}
	cout << endl;

	
	cout << "�ι�° ���׽�: ";
	p2.PrintList();
	cout << endl;
	cout << endl;

	cout << "/* ���� */" << endl;
	p1.Add(p2);
	cout << endl;

	cout << "/* ���� */" << endl;
	p1.Sub(p2);
	cout << endl;
	

	return 0;
}