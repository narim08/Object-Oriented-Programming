#include "Score.h"

/*Score 클래스 멤버 함수 정의*/
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


/*StudentScoreList 클래스 멤버 함수 정의*/
StudentScoreList::StudentScoreList():m_pHead{nullptr}, m_pTail{nullptr} {}
StudentScoreList::~StudentScoreList() {}

void StudentScoreList::Insert(Score* pScore) {
	/*처음 들어오는 경우 새로 연결*/
	if (m_pHead == nullptr) {
		m_pHead = pScore;
		m_pTail = pScore;
	}
	/*이어서 들어오는 경우 오름차순에 맞게 추가*/
	else { 
		Score* pCurr = m_pHead; //현 위치 가리킬 노드

		while (pCurr) { //끝까지 탐색해서 새로 들어온 노드가 들어갈 위치 찾을 때까지 반복
			if (pCurr->GetAvg() < pScore->GetAvg()) { //뒤에 추가해야되는 경우
				pCurr = pCurr->GetNext(); //다음 위치로 옮겨 가리킴
			}
			else
				break;
		}

		if (pCurr != nullptr) { //처음이나 중간에 들어가는 경우
			Score* pPrev = pCurr->GetPrev(); //이전 위치 가리킬 노드
			
			if (pPrev) { //이전 위치가 존재하는 경우
				/*이전 위치와 이중 연결*/
				pPrev->SetNext(pScore);
				pScore->SetPrev(pPrev);
			}
			/*현 위치와 이중 연결*/
			pScore->SetNext(pCurr);
			pCurr->SetPrev(pScore);

			if (pCurr == m_pHead) { //처음에 들어오는 경우
				m_pHead = pScore; //헤드 포인터를 새 노드로 옮김
			}
		}

		else { //끝에 들어가는 경우
			/*끝과 이중 연결*/
			m_pTail->SetNext(pScore);
			pScore->SetPrev(m_pTail); 
			m_pTail = pScore; //끝 설정
		}
	}
}

void StudentScoreList::PrintList(bool isAscending) { //true: 오름차순 / false: 내림차순
	if (isAscending == true) {
		/*이미 오름차순 정렬되어있으므로 처음부터 출력*/
		Score* pCurr = m_pHead;
		while (pCurr) {
			cout << pCurr->GetAvg() << "  ";
			pCurr = pCurr->GetNext(); //다음으로 이동
		}
	}
	else { 
		/*내림차순인 경우 끝에서부터 역순으로 출력*/
		Score* pCurr = m_pTail;
		while (pCurr) {
			cout << pCurr->GetAvg() << "  ";
			pCurr = pCurr->GetPrev(); //이전으로 이동
		}
	}
	cout << endl;
}