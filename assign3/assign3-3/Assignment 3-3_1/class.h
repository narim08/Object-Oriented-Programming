#include <iostream>
using namespace std;

class Sale
{
private:
	double Price;

public:
	Sale();
	Sale(double ThePrice);
	~Sale();

	double GetPrice(); //���� ��ȯ
	virtual double Bill(); //���� �Լ� (�ڽ� Ŭ�������� �������̵� �ǹǷ� �̰� ���õ�)
	double Savings(Sale& Other); //�� ���� ���� ���
	bool operator < (Sale& Other); //�� ���� ��
};

class DiscountSale : public Sale
{
private:
	double Discount;

public:
	DiscountSale();
	DiscountSale(double ThePrice, double theDiscount);
	~DiscountSale();

	double Bill(); //���� ���� ����� ��ȯ
	double Savings(DiscountSale& Other); //�� ���� ���� ���
	bool operator < (DiscountSale& second); //���ε� �� ���� ��
};