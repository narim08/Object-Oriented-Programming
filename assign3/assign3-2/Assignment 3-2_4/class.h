#include <iostream>
#include <string.h>
using namespace std;

class Term //각 항을 나타내는 노드
{
private:
	int m_Coefficient; //계수
	int m_Exponent; //지수
	Term* m_pNext;

public:
	Term();
	~Term();

	void SetCoeff(int coeff); //계수값 설정
	void SetExponent(int exponent); //지수값 설정
	int GetCoeff(); //계수값 반환
	int GetExponent(); //지수값 반환
	void SetNext(Term* pNext); //m_pNext값 설정
	Term* GetNext(); //m_pNext값 반환
};


class Polynomial { //다항식
private:
	Term* m_pHead;

public:
	Polynomial();
	~Polynomial();

	void Insert(Term* pTerm); //노드 추가후 연결
	void PrintList(); //총 출력
	void Add(Polynomial& poly); //덧셈 연산
	void Sub(Polynomial& poly); //뺄셈 연산
};