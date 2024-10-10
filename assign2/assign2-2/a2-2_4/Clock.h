#include <iostream>
using namespace std;
class Clock
{
public:
	Clock(); //생성자
	~Clock(); //소멸자

	void increaseHour(); //시간을 증가(24시간은 다시 0시간으로 초기화)
	void increaseMinute(); //분을 시간으로 증가
	void increaseSecond(); //초를 분으로 증가
	void setTime(int second); //초를 입력받아서 변환후 출력


private:
	void setHour(int hour); //24시간 미만일 시 저장, 이상이면 증가함수로 전달
	void setMinute(int minute); //60분 미만일 시 저장, 이상이면 증가함수로 전달
	void setSecond(int second); //60초 미만일 시 저장, 이상이면 증가함수로 전달

	int hour;
	int minute;
	int second;
};