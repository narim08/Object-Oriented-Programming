#include "class.h"

int main()
{
	/*첫번째 다항식 정보 설정*/
	Polynomial p1;
	int n, e, c;
	
	cout << "첫번째 다항식의 항 개수: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		Term* pNew = new Term();
		cout << "계수: "; cin >> c; pNew->SetCoeff(c);
		cout << "지수: "; cin >> e; pNew->SetExponent(e);
		p1.Insert(pNew);
	}
	cout << endl;
	cout << "첫번째 다항식: ";
	p1.PrintList();
	cout << endl;
	cout << endl;


	/*두번째 다항식 정보 설정*/
	Polynomial p2;
	int n2, e2, c2;

	cout << "두번째 다항식의 항 개수: ";
	cin >> n2;

	for (int i = 0; i < n2; i++) {
		Term* pNew = new Term();
		cout << "계수: "; cin >> c2; pNew->SetCoeff(c2);
		cout << "지수: "; cin >> e2; pNew->SetExponent(e2);
		p2.Insert(pNew);
	}
	cout << endl;

	
	cout << "두번째 다항식: ";
	p2.PrintList();
	cout << endl;
	cout << endl;

	cout << "/* 덧셈 */" << endl;
	p1.Add(p2);
	cout << endl;

	cout << "/* 뺄셈 */" << endl;
	p1.Sub(p2);
	cout << endl;
	

	return 0;
}