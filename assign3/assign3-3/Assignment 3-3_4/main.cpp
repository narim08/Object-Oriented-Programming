#include "Score.h"

int main()
{
	StudentScoreList list; //����Ʈ ��ü ����

	int n = 0; //�л� �� �Է�
	cout << "�л� ��: "; cin >> n;
	cout << endl;

	Score* std = new Score[n]; //���� ��ü �迭 �����Ҵ�


	cout << "/* ���� �Է� */" << endl;
	for (int i = 0; i < n; i++) {
		double m = 0, e = 0, s = 0; //����, ����, ���� ����
		
		cout << "���� ����: "; cin >> m;
		cout << "���� ����: "; cin >> e;
		cout << "���� ����: "; cin >> s;

		double avg = (m + e + s) / 3; //��� ���
		cout << "�л�" << i + 1 << "�� ���: " << avg << endl;
		cout << endl;

		std[i].SetAvg(avg); //��� ���� ����
		list.Insert(&std[i]); //�������� �߰�
	}
	cout << endl;


	cout << "��������: 1 / ��������: 2" << endl;
	int num = 0;
	cin >> num;
	switch (num) {
	case 1:
		list.PrintList(true);
		break;
	case 2:
		list.PrintList(false);
		break;
	default:
		cout << "�߸��� ��ȣ�� �Է��߽��ϴ�." << endl;
	}

	delete[] std; //�����Ҵ� ����
	return 0;
}