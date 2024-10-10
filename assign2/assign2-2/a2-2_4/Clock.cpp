#include "Clock.h"
using namespace std;

Clock::Clock():hour(0), minute(0), second(0) {} //생성자 (변수 초기화 시킴)

Clock::~Clock(){} //소멸자


void Clock::increaseHour() //시간을 증가 (24시간은 다시 0시간으로 초기화)
{
	hour++;
}
void Clock::increaseMinute() //분을 초기화 시키고 시간 증가
{
	minute = 0;
	hour++;
}
void Clock::increaseSecond() //초를 초기화 시키고 분을 증가
{
	second = 0;
	minute++;
}

void Clock::setTime(int sec) //초를 입력받아서 변환후 출력
{
	setHour(sec / 3600);
	setMinute((sec / 60) % 60);
	setSecond(sec % 60);

	cout << hour << ":" << minute << ":" << second;
}

void Clock::setHour(int h) //24시간 미만일 시 저장, 이상이면 증가함수로 전달
{
	if (h >= 24) {
		increaseHour();
	}
	else {
		hour = h;
	}
}
void Clock::setMinute(int m) //60분 미만일 시 저장, 이상이면 증가함수로 전달
{
	if (m == 60) {
		increaseMinute();
	}
	else {
		minute = m;
	}
}
void Clock::setSecond(int s) //60초 미만일 시 저장, 이상이면 증가함수로 전달
{
	if (s == 60) {
		increaseSecond();
	}
	else {
		second = s;
	}
}