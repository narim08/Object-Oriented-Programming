#include "class.h"

/*Term 클래스 멤버함수 정의*/
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


/*Polynomial 클래스 멤버함수 정의*/
Polynomial::Polynomial():m_pHead{nullptr}{}
Polynomial::~Polynomial() {
	Term* pCurr = m_pHead;
	while (pCurr) { //마지막까지 반복
		Term* pNext = pCurr->GetNext(); //다음 항 정보 저장
		delete pCurr; //현재 항 삭제
		pCurr = pNext; //다음 항으로 이동
	}
	m_pHead = nullptr;
}

void Polynomial::Insert(Term* pTerm) {
	/*처음 들어온 경우 헤드포인터를 해당 값으로 설정*/
	if (m_pHead == nullptr) { 
		m_pHead = pTerm; 
		return;
	}

	/*두번째 이후부터 지수 검사하여 순서에 맞게 리스트로 연결*/
	Term* pPrev = nullptr; //이전 값 
	Term* pCurr = m_pHead; //현재 값

	while (pCurr) { //존재하는 노드들 안에서 끝까지 검사
		if (pCurr->GetExponent() > pTerm->GetExponent()) { //새로 추가할 노드가 뒤에 연결 되는 경우
			pPrev = pCurr; //이전 포인터에 현재 항 저장
			pCurr = pCurr->GetNext(); //현재 포인터를 다음 항으로 이동
		}
		else {
			pCurr = pCurr->GetNext();
		}
	}
	if (pPrev!=nullptr) { //앞에 if문을 작업을 수행한 경우
		pTerm->SetNext(pPrev->GetNext()); //추가할 항의 위치를 설정
		pPrev->SetNext(pTerm); //이전 항의 다음 위치를 추가 항으로 설정
	}
	else { //추가 항이 제일 지수가 높아서 앞에 위치해야 하는 경우
		pTerm->SetNext(m_pHead); //첫번째로 설정
		m_pHead = pTerm;
	}
}

void Polynomial::PrintList() {
	Term* pCurr = m_pHead;

	while (pCurr)
	{
		if (pCurr->GetExponent() == 0) { //상수항인 경우
			cout << pCurr->GetCoeff(); //계수만 출력
			break;
		}
		else {
			cout << pCurr->GetCoeff() << "X^" << pCurr->GetExponent();
		}

		if (pCurr->GetCoeff() > 0 && pCurr->GetNext() != nullptr) {//항이 양수인 경우 덧셈으로 출력
			cout << " + ";
		}
		pCurr = pCurr->GetNext(); //다음 항으로 이동
	}
	cout << endl;
}

void Polynomial::Add(Polynomial& poly) {
	Polynomial p3; //덧셈 결과 저장 리스트
	Term* p1 = m_pHead; //첫번째 다항식
	Term* p2 = poly.m_pHead; //두번째 다항식
	int coeff = 0; //계수 덧셈 값

	while (p1 && p2) { //두 다항식 모두 항이 존재할 때 검사
		if (p1->GetExponent() == p2->GetExponent()) { //지수가 같을 때
			coeff = p1->GetCoeff() + p2->GetCoeff(); //계수끼리 더하여 저장

			if (coeff != 0) { //계수가 0이 아니어서 항이 존재하게 될 경우
				Term* pNew = new Term; //임시 새 노드 생성
				pNew->SetExponent(p1->GetExponent()); //지수 설정
				pNew->SetCoeff(coeff); //계수 설정
				p3.Insert(pNew); //설정한 노드 리스트에 추가
			}
			p1 = p1->GetNext(); //다음 항으로 이동(계수가 0인 경우 노드 추가 없이 이동)
			p2 = p2->GetNext();
		}
		else if (p1->GetExponent() < p2->GetExponent()) { //p2가 더 클 경우 p2값 그대로 저장
			Term* pNew = new Term;
			pNew->SetExponent(p2->GetExponent());
			pNew->SetCoeff(p2->GetCoeff());
			p3.Insert(pNew);
			p2 = p2->GetNext();
		}
		else { //p1이 더 클 경우 p1값 그대로 저장
			Term* pNew = new Term;
			pNew->SetExponent(p1->GetExponent());
			pNew->SetCoeff(p1->GetCoeff());
			p3.Insert(pNew);
			p1 = p1->GetNext();
		}
	}

	/*남는 항들이 있으면 똑같이 저장 후 연결*/
	while (p2) { //p2가 남는 경우
		Term* pNew = new Term;
		pNew->SetExponent(p2->GetExponent());
		pNew->SetCoeff(p2->GetCoeff());
		p3.Insert(pNew);
		p2 = p2->GetNext();
	}
	while (p1) { //p1이 남는 경우
		Term* pNew = new Term;
		pNew->SetExponent(p1->GetExponent());
		pNew->SetCoeff(p1->GetCoeff());
		p3.Insert(pNew);
		p1 = p1->GetNext();
	}

	p3.PrintList();
}

void Polynomial::Sub(Polynomial& poly) {
	Polynomial p3; //뺄셈 결과 저장 리스트
	Term* p1 = m_pHead; //첫번째 다항식
	Term* p2 = poly.m_pHead; //두번째 다항식
	int coeff = 0; //계수 뺄셈 값

	while (p1 && p2) {
		if (p1->GetExponent() == p2->GetExponent()) {
			coeff = p1->GetCoeff() - p2->GetCoeff();
			if (coeff != 0) {
				Term* pNew = new Term; //임시 새 노드 생성
				pNew->SetExponent(p1->GetExponent()); //지수 설정
				pNew->SetCoeff(coeff); //계수 설정
				p3.Insert(pNew); //설정한 노드 리스트에 추가
			}
			p1 = p1->GetNext(); //다음 항으로 이동(계수가 0인 경우 노드 추가 없이 이동)
			p2 = p2->GetNext();
		}
		else if (p1->GetExponent() < p2->GetExponent()) { //p2가 더 클 경우 p2값 그대로 저장
			Term* pNew = new Term;
			pNew->SetExponent(p2->GetExponent());
			pNew->SetCoeff(-1*p2->GetCoeff()); //부호 반전
			p3.Insert(pNew);
			p2 = p2->GetNext();
		}
		else { //p1이 더 클 경우 p1값 그대로 저장
			Term* pNew = new Term;
			pNew->SetExponent(p1->GetExponent());
			pNew->SetCoeff(p1->GetCoeff());
			p3.Insert(pNew);
			p1 = p1->GetNext();
		}
	}

	/*남는 항들이 있으면 똑같이 저장 후 연결*/
	while (p2) { //p2가 남는 경우
		Term* pNew = new Term;
		pNew->SetExponent(p2->GetExponent());
		pNew->SetCoeff(-1*p2->GetCoeff()); //부호 반전
		p3.Insert(pNew);
		p2 = p2->GetNext();
	}
	while (p1) { //p1이 남는 경우
		Term* pNew = new Term;
		pNew->SetExponent(p1->GetExponent());
		pNew->SetCoeff(p1->GetCoeff());
		p3.Insert(pNew);
		p1 = p1->GetNext();
	}

	p3.PrintList();
}