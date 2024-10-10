#include "CSVLoader.h"
#include <iostream>


int main()
{
	char fname[20] = "CSVLoader_Data.txt";
	CSVLoader csv(fname); //���� �̸� ����


	/*���� ����*/
	ifstream finput(fname);
	if (finput.fail()) { //���� ó��
		cout << "������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	char line[128]; //���Ͽ��� �о���� �迭
	int i = 0;
	float lineF[128] = {}; //�Ǽ��� ��ȯ�Ͽ� ������ �迭
	string readStr = ""; //���� ���ڿ��� ����
	string STR; //�� ��ĥ ���ڿ�


	while (finput.getline(line, ',')) { //�޸����� ����
		readStr = line; //���� �� stringŸ�Կ� ����
		STR += readStr + "\n"; //����� �Բ� �� ���ڿ��� ����
		/*
		lineF[i] = (float)atof(readStr.c_str());
		cout << lineF[i] << ' ';
		i++;
		if (i % 2 == 0) {
			cout << endl;
		}
		*/
	}
	
	cout << STR;

	finput.close();
	return 0;
}