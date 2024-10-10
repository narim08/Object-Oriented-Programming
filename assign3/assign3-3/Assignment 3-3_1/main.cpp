#include "class.h"

int main()
{
	double p1, p2; //item1, item2의 각 가격
	char d[5]; //할인율

	/*정보 입력 받기*/
	cout << "==============================" << endl;
	cout << "Price Compare Program" << endl;
	cout<<"==============================" << endl;
	cout << "Insert item1 price: $"; cin >> p1;
	cout << "Insert item2 price: $"; cin >> p2;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Insert discount percent: "; cin >> d;
	cout << "------------------------------" << endl;
	cout << "Result:" << endl;
	
	double dis = atof(d); //'%'제외 숫자만 저장

	/*item1 할인 가격 설정*/
	DiscountSale item1(p1, dis);

	/*item2 할인 가격 설정*/
	DiscountSale item2(p2, dis);

	/*가격 비교 후 출력 ('<'연산자만 사용 가능)*/
	if (item1 < item2) { //item2의 가격이 더 비싼 경우
		cout << "Discont price of item1 is cheaper." << endl;
		cout << "Saving discount price is $"; printf("%.1f", item2.Savings(item1));
	}
	else if (item2 < item1) { //item1의 가격이 더 비싼 경우
		cout << "Discont price of item2 is cheaper." << endl;
		cout << "Saving discount price is $"; printf("%.1f", item1.Savings(item2));
	}
	else { //두 가격이 동일한 경우
		cout << "Both item are the same price." << endl;
	}
	cout << endl;

	return 0;
}