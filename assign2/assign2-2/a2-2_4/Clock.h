#include <iostream>
using namespace std;
class Clock
{
public:
	Clock(); //������
	~Clock(); //�Ҹ���

	void increaseHour(); //�ð��� ����(24�ð��� �ٽ� 0�ð����� �ʱ�ȭ)
	void increaseMinute(); //���� �ð����� ����
	void increaseSecond(); //�ʸ� ������ ����
	void setTime(int second); //�ʸ� �Է¹޾Ƽ� ��ȯ�� ���


private:
	void setHour(int hour); //24�ð� �̸��� �� ����, �̻��̸� �����Լ��� ����
	void setMinute(int minute); //60�� �̸��� �� ����, �̻��̸� �����Լ��� ����
	void setSecond(int second); //60�� �̸��� �� ����, �̻��̸� �����Լ��� ����

	int hour;
	int minute;
	int second;
};