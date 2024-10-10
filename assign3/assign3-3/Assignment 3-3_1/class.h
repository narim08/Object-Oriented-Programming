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

	double GetPrice(); //가격 반환
	virtual double Bill(); //가상 함수 (자식 클래스에서 오버라이딩 되므로 이건 무시됨)
	double Savings(Sale& Other); //두 가격 차이 계산
	bool operator < (Sale& Other); //두 가격 비교
};

class DiscountSale : public Sale
{
private:
	double Discount;

public:
	DiscountSale();
	DiscountSale(double ThePrice, double theDiscount);
	~DiscountSale();

	double Bill(); //할인 가격 계산후 반환
	double Savings(DiscountSale& Other); //두 가격 차이 계산
	bool operator < (DiscountSale& second); //할인된 두 가격 비교
};