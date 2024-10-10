#include "Score.h"

/*Score Ŭ���� ��� �Լ� ����*/
Score::Score() :m_pNext{ nullptr }, m_pPrev{ nullptr }, m_Avg(0) {}
Score::~Score(){}

void Score::SetAvg(double avg) {
	m_Avg = avg;
}

void Score::SetNext(Score* pNext) {
	m_pNext = pNext;
}

void Score::SetPrev(Score* pPrev) {
	m_pPrev = pPrev;
}

double Score::GetAvg() {
	return m_Avg;
}

Score* Score::GetNext() {
	return m_pNext;
}

Score* Score::GetPrev() {
	return m_pPrev;
}


/*StudentScoreList Ŭ���� ��� �Լ� ����*/
StudentScoreList::StudentScoreList():m_pHead{nullptr}, m_pTail{nullptr} {}
StudentScoreList::~StudentScoreList() {}

void StudentScoreList::Insert(Score* pScore) {
	/*ó�� ������ ��� ���� ����*/
	if (m_pHead == nullptr) {
		m_pHead = pScore;
		m_pTail = pScore;
	}
	/*�̾ ������ ��� ���������� �°� �߰�*/
	else { 
		Score* pCurr = m_pHead; //�� ��ġ ����ų ���

		while (pCurr) { //������ Ž���ؼ� ���� ���� ��尡 �� ��ġ ã�� ������ �ݺ�
			if (pCurr->GetAvg() < pScore->GetAvg()) { //�ڿ� �߰��ؾߵǴ� ���
				pCurr = pCurr->GetNext(); //���� ��ġ�� �Ű� ����Ŵ
			}
			else
				break;
		}

		if (pCurr != nullptr) { //ó���̳� �߰��� ���� ���
			Score* pPrev = pCurr->GetPrev(); //���� ��ġ ����ų ���
			
			if (pPrev) { //���� ��ġ�� �����ϴ� ���
				/*���� ��ġ�� ���� ����*/
				pPrev->SetNext(pScore);
				pScore->SetPrev(pPrev);
			}
			/*�� ��ġ�� ���� ����*/
			pScore->SetNext(pCurr);
			pCurr->SetPrev(pScore);

			if (pCurr == m_pHead) { //ó���� ������ ���
				m_pHead = pScore; //��� �����͸� �� ���� �ű�
			}
		}

		else { //���� ���� ���
			/*���� ���� ����*/
			m_pTail->SetNext(pScore);
			pScore->SetPrev(m_pTail); 
			m_pTail = pScore; //�� ����
		}
	}
}

void StudentScoreList::PrintList(bool isAscending) { //true: �������� / false: ��������
	if (isAscending == true) {
		/*�̹� �������� ���ĵǾ������Ƿ� ó������ ���*/
		Score* pCurr = m_pHead;
		while (pCurr) {
			cout << pCurr->GetAvg() << "  ";
			pCurr = pCurr->GetNext(); //�������� �̵�
		}
	}
	else { 
		/*���������� ��� ���������� �������� ���*/
		Score* pCurr = m_pTail;
		while (pCurr) {
			cout << pCurr->GetAvg() << "  ";
			pCurr = pCurr->GetPrev(); //�������� �̵�
		}
	}
	cout << endl;
}