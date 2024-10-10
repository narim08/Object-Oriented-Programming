#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CSVLoader
{
public:
	static constexpr unsigned int MAX_BUFFER_SIZE = 128;

public:
	CSVLoader(); //������
	CSVLoader(char* path); //�����ڿ��� �ʱ�ȭ ��Ŵ
	~CSVLoader(); //�Ҹ���

	//float** getData() const; //������ ����
	//int getRows() const; //���� ���� ����
	//int getCols() const; //���� ���� ����

	void parse(const char* path); //������ ���� ��ȯ
	void print(void); //�� ���

private:
	float** data; //��ȯ �� 2���� �迭
	int cols; //��
	int rows; //��
};