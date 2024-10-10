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
	CSVLoader(); //생성자
	CSVLoader(char* path); //생성자에서 초기화 시킴
	~CSVLoader(); //소멸자

	//float** getData() const; //데이터 받음
	//int getRows() const; //행의 개수 받음
	//int getCols() const; //열의 개수 받음

	void parse(const char* path); //데이터 형식 변환
	void print(void); //총 출력

private:
	float** data; //변환 할 2차원 배열
	int cols; //열
	int rows; //행
};