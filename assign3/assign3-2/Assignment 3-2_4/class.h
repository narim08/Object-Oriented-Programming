#include <iostream>
#include <string.h>
using namespace std;

class Term //�� ���� ��Ÿ���� ���
{
private:
	int m_Coefficient; //���
	int m_Exponent; //����
	Term* m_pNext;

public:
	Term();
	~Term();

	void SetCoeff(int coeff); //����� ����
	void SetExponent(int exponent); //������ ����
	int GetCoeff(); //����� ��ȯ
	int GetExponent(); //������ ��ȯ
	void SetNext(Term* pNext); //m_pNext�� ����
	Term* GetNext(); //m_pNext�� ��ȯ
};


class Polynomial { //���׽�
private:
	Term* m_pHead;

public:
	Polynomial();
	~Polynomial();

	void Insert(Term* pTerm); //��� �߰��� ����
	void PrintList(); //�� ���
	void Add(Polynomial& poly); //���� ����
	void Sub(Polynomial& poly); //���� ����
};