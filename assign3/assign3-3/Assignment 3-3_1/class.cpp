#include "class.h"

/*Sale Ŭ���� ��� �Լ� ����*/
Sale::Sale():Price(0) {}
Sale::Sale(double ThePrice):Price(ThePrice) {}
Sale::~Sale() {}

double Sale::GetPrice() { //���� ��ȯ
	return Price;
}

double Sale::Bill(){ //���� �Լ� (�ڽ� Ŭ�������� �������̵� �ǹǷ� �̰� ���õ�)
	return 0;
} 

double Sale::Savings(Sale& Other) { //�� ���� ���� ���
	return (GetPrice() - Other.GetPrice());
}

bool Sale::operator < (Sale& Other) { //�� ���� ��
	return (Price < Other.GetPrice());
}


/*DiscountSale Ŭ���� ��� �Լ� ����*/
DiscountSale::DiscountSale():Discount(0) {}
DiscountSale::DiscountSale(double ThePrice, double theDiscount): Sale(ThePrice), Discount(theDiscount) {}
DiscountSale::~DiscountSale() {}

double DiscountSale::Bill() { //���� ���� ����� ��ȯ
	return (GetPrice() - (GetPrice() * (Discount / 100)));
}

double DiscountSale::Savings(DiscountSale& Other) { //�� ���� ���� ���
	return (Bill() - Other.Bill());
}

bool DiscountSale::operator < (DiscountSale& second) { //���ε� �� ���� ��
	return (Bill() < second.Bill());
}