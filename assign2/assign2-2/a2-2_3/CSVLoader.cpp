#include "CSVLoader.h"

CSVLoader::CSVLoader() //생성자에서 변수 초기화
{
	rows = 97; cols = 2;
	data = new float* [rows + 1]{};
	for (int i = 0; i < rows + 1; i++) {
		data[i] = new float[cols + 1];
	}
	data[rows][cols] = {};
}

CSVLoader::CSVLoader(char* path) //생성자에서 파일 경로 받음
{
	ifstream finput(path); //파일 읽기
	if (finput.fail()) { //예외 처리
		cout << "파일을 열 수 없습니다." << endl;
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
