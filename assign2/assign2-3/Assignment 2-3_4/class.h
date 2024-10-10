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

		float getElement(int row, int col) const; //��� �� ��ȯ
		float** getData() const; //�迭 ������ �� ��ȯ
		void setElement(const int row, const int col, float value); //��� �� ����
		void setData(const int rows, const int cols, float** data); //�迭 �� ����
		int getRows() const; //�� �� ��ȯ
		int getCols() const; //�� �� ��ȯ
		void setRows(const int rows); //�� �� ����
		void setCols(const int cols); //�� �� ����
		
		float determinant(); //��Ľ� ��� �� �� ��ȯ

	private:
		float** data;
		int rows;
		int cols;
	};
	/*�� ��� �� ����, ����, ���� ��� (��� r�� ��ȯ)*/
	Matrix& add(Matrix& r, Matrix& a, Matrix& b);
	Matrix& sub(Matrix& r, Matrix& a, Matrix& b);
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b);

	/*�� ��Ŀ����� ��Į�� ����, ����, ����, ������ ���*/
	Matrix& elementAdd(Matrix& r, Matrix& a, float v);
	Matrix& elementSub(Matrix& r, Matrix& a, float v);
	Matrix& elementMul(Matrix& r, Matrix& a, float v);
	Matrix& elementDiv(Matrix& r, Matrix& a, float v);

	/*�� ��Ŀ����� ��ġ���, �������, ����� ���*/
	Matrix& transpose(Matrix& r, Matrix& m);
	Matrix& adjoint(Matrix& r, Matrix& m);
	Matrix& inverse(Matrix& r, Matrix& m);
}