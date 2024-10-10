#include "Clock.h"
using namespace std;

Clock::Clock():hour(0), minute(0), second(0) {} //������ (���� �ʱ�ȭ ��Ŵ)

Clock::~Clock(){} //�Ҹ���


void Clock::increaseHour() //�ð��� ���� (24�ð��� �ٽ� 0�ð����� �ʱ�ȭ)
{
	hour++;
}
void Clock::increaseMinute() //���� �ʱ�ȭ ��Ű�� �ð� ����
{
	minute = 0;
	hour++;
}
void Clock::increaseSecond() //�ʸ� �ʱ�ȭ ��Ű�� ���� ����
{
	second = 0;
	minute++;
}

void Clock::setTime(int sec) //�ʸ� �Է¹޾Ƽ� ��ȯ�� ���
{
	setHour(sec / 3600);
	setMinute((sec / 60) % 60);
	setSecond(sec % 60);

	cout << hour << ":" << minute << ":" << second;
}

void Clock::setHour(int h) //24�ð� �̸��� �� ����, �̻��̸� �����Լ��� ����
{
	if (h >= 24) {
		increaseHour();
	}
	else {
		hour = h;
	}
}
void Clock::setMinute(int m) //60�� �̸��� �� ����, �̻��̸� �����Լ��� ����
{
	if (m == 60) {
		increaseMinute();
	}
	else {
		minute = m;
	}
}
void Clock::setSecond(int s) //60�� �̸��� �� ����, �̻��̸� �����Լ��� ����
{
	if (s == 60) {
		increaseSecond();
	}
	else {
		second = s;
	}
}