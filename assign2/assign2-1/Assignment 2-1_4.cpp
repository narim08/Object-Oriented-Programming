#include <iostream>
#include <fstream>
using namespace std;

class Txt //���ĺ� �迭 ������ Ŭ����
{
public:
	char ar[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
};


int main()
{
	Txt arr; //Ŭ���� ��ü ����
	char str[60]={}; //���Ͽ��� �о� �� ���ڿ��� ������ �迭
	char ostr[30] = {}; //���ĺ����� ��ȯ�� ���ڿ��� ������ �迭
	int n = 0, i, j, p = 0, k = 0; //���� ���� ������ ����, �ݺ��� ������ 

	ifstream finput("binary.txt"); //�б�� ���� ����
	ofstream foutput("alphabet.txt"); //����� ���� ����

	/*�б�� ���� ����ó��*/
	if (!finput) {
		cout << "������ �� �� �����ϴ�.";
		exit(1);
	}

	/*���� �о�ͼ� ����*/
	while (!finput.eof()) { 
		finput.getline(str, 60); 
	}

	/*���̳ʸ� ���ڸ� ���ĺ����� ��ȯ*/
	while (1)
	{
		for (i = p; str[i] != '1'; i++) { //1 ������ ������
			n++;
		}
		ostr[k++] = arr.ar[n];
		p = i+1;
		n = 0;
		if (str[p]==NULL) {
			break;
		}
	}
	foutput.write(ostr, k); //���Ͽ� ����

	/*���� �ݱ�*/
	finput.close();
	foutput.close();

	return 0;
}