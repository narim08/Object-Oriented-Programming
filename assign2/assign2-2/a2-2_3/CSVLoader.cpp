#include "CSVLoader.h"

CSVLoader::CSVLoader() //�����ڿ��� ���� �ʱ�ȭ
{
	rows = 97; cols = 2;
	data = new float* [rows + 1]{};
	for (int i = 0; i < rows + 1; i++) {
		data[i] = new float[cols + 1];
	}
	data[rows][cols] = {};
}

CSVLoader::CSVLoader(char* path) //�����ڿ��� ���� ��� ����
{
	ifstream finput(path); //���� �б�
	if (finput.fail()) { //���� ó��
		cout << "������ �� �� �����ϴ�." << endl;
		exit(1);
	}
}

CSVLoader::~CSVLoader()
{
	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete data;
}
/*
float** CSVLoader::getData() const
{
	
}

int CSVLoader::getRows() const
{
	
}
int CSVLoader::getCols() const
{

}
*/
void CSVLoader::parse(const char*path)
{
	
}
void CSVLoader::print(void)
{

}
