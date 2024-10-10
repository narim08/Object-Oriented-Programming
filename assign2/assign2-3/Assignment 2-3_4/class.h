#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

namespace ooplinalg {

	class Matrix
	{
	public:
		Matrix(); 
		Matrix(const Matrix& mat);
		Matrix(int rows, int cols);
		~Matrix();

		float getElement(int row, int col) const; //요소 값 반환
		float** getData() const; //배열 포인터 값 반환
		void setElement(const int row, const int col, float value); //요소 값 저장
		void setData(const int rows, const int cols, float** data); //배열 값 저장
		int getRows() const; //행 값 반환
		int getCols() const; //열 값 반환
		void setRows(const int rows); //행 값 저장
		void setCols(const int cols); //열 값 저장
		
		float determinant(); //행렬식 계산 후 값 반환

	private:
		float** data;
		int rows;
		int cols;
	};
	/*두 행렬 간 덧셈, 뺄셈, 곱셈 계산 (결과 r값 반환)*/
	Matrix& add(Matrix& r, Matrix& a, Matrix& b);
	Matrix& sub(Matrix& r, Matrix& a, Matrix& b);
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b);

	/*한 행렬에서의 스칼라 덧셈, 뺄셈, 곱셈, 나눗셈 계산*/
	Matrix& elementAdd(Matrix& r, Matrix& a, float v);
	Matrix& elementSub(Matrix& r, Matrix& a, float v);
	Matrix& elementMul(Matrix& r, Matrix& a, float v);
	Matrix& elementDiv(Matrix& r, Matrix& a, float v);

	/*한 행렬에서의 전치행렬, 수반행렬, 역행렬 계산*/
	Matrix& transpose(Matrix& r, Matrix& m);
	Matrix& adjoint(Matrix& r, Matrix& m);
	Matrix& inverse(Matrix& r, Matrix& m);
}