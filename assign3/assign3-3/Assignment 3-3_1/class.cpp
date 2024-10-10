#include "class.h"

/*Sale 클래스 멤버 함수 정의*/
Sale::Sale():Price(0) {}
Sale::Sale(double ThePrice):Price(ThePrice) {}
Sale::~Sale() {}

double Sale::GetPrice() { //가격 반환
	return Price;
}

double Sale::Bill(){ //가상 함수 (자식 클래스에서 오버라이딩 되므로 이건 무시됨)
	return 0;
} 

double Sale::Savings(Sale& Other) { //두 가격 차이 계산
	return (GetPrice() - Other.GetPrice());
}

bool Sale::operator < (Sale& Other) { //두 가격 비교
	return (Price < Other.GetPrice());
}


/*DiscountSale 클래스 멤버 함수 정의*/
DiscountSale::DiscountSale():Discount(0) {}
DiscountSale::DiscountSale(double ThePrice, double theDiscount): Sale(ThePrice), Discount(theDiscount) {}
DiscountSale::~DiscountSale() {}

double DiscountSale::Bill() { //할인 가격 계산후 반환
	return (GetPrice() - (GetPrice() * (Discount / 100)));
}

double DiscountSale::Savings(DiscountSale& Other) { //두 가격 차이 계산
	return (Bill() - Other.Bill());
}

bool DiscountSale::operator < (DiscountSale& second) { //할인된 두 가격 비교
	return (Bill() < second.Bill());
}