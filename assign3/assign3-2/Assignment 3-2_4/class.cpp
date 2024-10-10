#include "class.h"

/*Term Ŭ���� ����Լ� ����*/
Term::Term():m_Coefficient(0), m_Exponent(0), m_pNext{nullptr}{}
Term::~Term() {}

void Term::SetCoeff(int coeff) {
	m_Coefficient = coeff;
}

void Term::SetExponent(int exponent) {
	m_Exponent = exponent;
}

void Term::SetNext(Term* pNext) {
	m_pNext = pNext;
}

int Term::GetCoeff() {
	return m_Coefficient;
}

int Term::GetExponent() {
	return m_Exponent;
}

Term* Term::GetNext() {
	return m_pNext;
}


/*Polynomial Ŭ���� ����Լ� ����*/
Polynomial::Polynomial():m_pHead{nullptr}{}
Polynomial::~Polynomial() {
	Term* pCurr = m_pHead;
	while (pCurr) { //���������� �ݺ�
		Term* pNext = pCurr->GetNext(); //���� �� ���� ����
		delete pCurr; //���� �� ����
		pCurr = pNext; //���� ������ �̵�
	}
	m_pHead = nullptr;
}

void Polynomial::Insert(Term* pTerm) {
	/*ó�� ���� ��� ��������͸� �ش� ������ ����*/
	if (m_pHead == nullptr) { 
		m_pHead = pTerm; 
		return;
	}

	/*�ι�° ���ĺ��� ���� �˻��Ͽ� ������ �°� ����Ʈ�� ����*/
	Term* pPrev = nullptr; //���� �� 
	Term* pCurr = m_pHead; //���� ��

	while (pCurr) { //�����ϴ� ���� �ȿ��� ������ �˻�
		if (pCurr->GetExponent() > pTerm->GetExponent()) { //���� �߰��� ��尡 �ڿ� ���� �Ǵ� ���
			pPrev = pCurr; //���� �����Ϳ� ���� �� ����
			pCurr = pCurr->GetNext(); //���� �����͸� ���� ������ �̵�
		}
		else {
			pCurr = pCurr->GetNext();
		}
	}
	if (pPrev!=nullptr) { //�տ� if���� �۾��� ������ ���
		pTerm->SetNext(pPrev->GetNext()); //�߰��� ���� ��ġ�� ����
		pPrev->SetNext(pTerm); //���� ���� ���� ��ġ�� �߰� ������ ����
	}
	else { //�߰� ���� ���� ������ ���Ƽ� �տ� ��ġ�ؾ� �ϴ� ���
		pTerm->SetNext(m_pHead); //ù��°�� ����
		m_pHead = pTerm;
	}
}

void Polynomial::PrintList() {
	Term* pCurr = m_pHead;

	while (pCurr)
	{
		if (pCurr->GetExponent() == 0) { //������� ���
			cout << pCurr->GetCoeff(); //����� ���
			break;
		}
		else {
			cout << pCurr->GetCoeff() << "X^" << pCurr->GetExponent();
		}

		if (pCurr->GetCoeff() > 0 && pCurr->GetNext() != nullptr) {//���� ����� ��� �������� ���
			cout << " + ";
		}
		pCurr = pCurr->GetNext(); //���� ������ �̵�
	}
	cout << endl;
}

void Polynomial::Add(Polynomial& poly) {
	Polynomial p3; //���� ��� ���� ����Ʈ
	Term* p1 = m_pHead; //ù��° ���׽�
	Term* p2 = poly.m_pHead; //�ι�° ���׽�
	int coeff = 0; //��� ���� ��

	while (p1 && p2) { //�� ���׽� ��� ���� ������ �� �˻�
		if (p1->GetExponent() == p2->GetExponent()) { //������ ���� ��
			coeff = p1->GetCoeff() + p2->GetCoeff(); //������� ���Ͽ� ����

			if (coeff != 0) { //����� 0�� �ƴϾ ���� �����ϰ� �� ���
				Term* pNew = new Term; //�ӽ� �� ��� ����
				pNew->SetExponent(p1->GetExponent()); //���� ����
				pNew->SetCoeff(coeff); //��� ����
				p3.Insert(pNew); //������ ��� ����Ʈ�� �߰�
			}
			p1 = p1->GetNext(); //���� ������ �̵�(����� 0�� ��� ��� �߰� ���� �̵�)
			p2 = p2->GetNext();
		}
		else if (p1->GetExponent() < p2->GetExponent()) { //p2�� �� Ŭ ��� p2�� �״�� ����
			Term* pNew = new Term;
			pNew->SetExponent(p2->GetExponent());
			pNew->SetCoeff(p2->GetCoeff());
			p3.Insert(pNew);
			p2 = p2->GetNext();
		}
		else { //p1�� �� Ŭ ��� p1�� �״�� ����
			Term* pNew = new Term;
			pNew->SetExponent(p1->GetExponent());
			pNew->SetCoeff(p1->GetCoeff());
			p3.Insert(pNew);
			p1 = p1->GetNext();
		}
	}

	/*���� �׵��� ������ �Ȱ��� ���� �� ����*/
	while (p2) { //p2�� ���� ���
		Term* pNew = new Term;
		pNew->SetExponent(p2->GetExponent());
		pNew->SetCoeff(p2->GetCoeff());
		p3.Insert(pNew);
		p2 = p2->GetNext();
	}
	while (p1) { //p1�� ���� ���
		Term* pNew = new Term;
		pNew->SetExponent(p1->GetExponent());
		pNew->SetCoeff(p1->GetCoeff());
		p3.Insert(pNew);
		p1 = p1->GetNext();
	}

	p3.PrintList();
}

void Polynomial::Sub(Polynomial& poly) {
	Polynomial p3; //���� ��� ���� ����Ʈ
	Term* p1 = m_pHead; //ù��° ���׽�
	Term* p2 = poly.m_pHead; //�ι�° ���׽�
	int coeff = 0; //��� ���� ��

	while (p1 && p2) {
		if (p1->GetExponent() == p2->GetExponent()) {
			coeff = p1->GetCoeff() - p2->GetCoeff();
			if (coeff != 0) {
				Term* pNew = new Term; //�ӽ� �� ��� ����
				pNew->SetExponent(p1->GetExponent()); //���� ����
				pNew->SetCoeff(coeff); //��� ����
				p3.Insert(pNew); //������ ��� ����Ʈ�� �߰�
			}
			p1 = p1->GetNext(); //���� ������ �̵�(����� 0�� ��� ��� �߰� ���� �̵�)
			p2 = p2->GetNext();
		}
		else if (p1->GetExponent() < p2->GetExponent()) { //p2�� �� Ŭ ��� p2�� �״�� ����
			Term* pNew = new Term;
			pNew->SetExponent(p2->GetExponent());
			pNew->SetCoeff(-1*p2->GetCoeff()); //��ȣ ����
			p3.Insert(pNew);
			p2 = p2->GetNext();
		}
		else { //p1�� �� Ŭ ��� p1�� �״�� ����
			Term* pNew = new Term;
			pNew->SetExponent(p1->GetExponent());
			pNew->SetCoeff(p1->GetCoeff());
			p3.Insert(pNew);
			p1 = p1->GetNext();
		}
	}

	/*���� �׵��� ������ �Ȱ��� ���� �� ����*/
	while (p2) { //p2�� ���� ���
		Term* pNew = new Term;
		pNew->SetExponent(p2->GetExponent());
		pNew->SetCoeff(-1*p2->GetCoeff()); //��ȣ ����
		p3.Insert(pNew);
		p2 = p2->GetNext();
	}
	while (p1) { //p1�� ���� ���
		Term* pNew = new Term;
		pNew->SetExponent(p1->GetExponent());
		pNew->SetCoeff(p1->GetCoeff());
		p3.Insert(pNew);
		p1 = p1->GetNext();
	}

	p3.PrintList();
}