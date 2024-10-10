#include "class.h"

int main()
{
	cout << "/* Professor */" << endl;
	char pName[32];
	char pNum[11];
	char pMajor[32];
	int pAge = 0;

	cout << "Name: "; scanf_s("%[^\n]%*c", pName, 31);
	cout << "Age: "; scanf_s("%d%*c", &pAge);
	cout << "Number: "; scanf_s("%[^\n]%*c", pNum, 10);
	cout << "Major: "; scanf_s("%[^\n]%*c", pMajor, 31);
	cout << endl;

	Professor pro; //클래스 객체 생성후 set함수로 정보 설정
	pro.setAge(pAge);
	pro.setName(pName);
	pro.setProfessorNum(pNum);
	pro.setMajor(pMajor);
	pro.Say(); //정보 출력

	cout << endl;
	cout << endl;

	cout << "/* Student */" << endl;
	char sName[32];
	char sNum[11];
	char sMajor[32];
	int sAge = 0, year = 0;

	cout << "Name: "; scanf_s("%[^\n]%*c", sName, 31);
	cout << "Age: "; scanf_s("%d%*c", &sAge);
	cout << "School Year: "; scanf_s("%d%*c", &year);
	cout << "Number: "; scanf_s("%[^\n]%*c", sNum, 11);
	cout << "Major: "; scanf_s("%[^\n]%*c", sMajor, 31);
	cout << endl;

	Student std; //클래스 객체 생성후 set함수로 정보 설정
	std.setAge(sAge);
	std.setName(sName);
	std.setStudentNum(sNum);
	std.setSchoolYear(year);
	std.setMajor(sMajor);
	std.Say(); //정보 출력

	return 0;
}