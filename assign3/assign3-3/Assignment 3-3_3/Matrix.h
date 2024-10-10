#include <iostream>
using namespace std;

class Matrix
{
private:
	double mat[3][3];

public:
	Matrix();
	Matrix(double mat[3][3]);
	~Matrix();

	void printMat(); //행렬 출력

	/*연산자 오버로딩*/
	Matrix operator += (const Matrix& Other);
	Matrix operator -= (const Matrix& Other);
	Matrix operator * (const Matrix& Other);
};
