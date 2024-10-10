#include <iostream>
using namespace std;

/*직렬 회로 계산*/
void Series(int Vs, int R1, int R2)
{
	int m=0, j=0, k=0; //분모, 분자, 소인수
	j = Vs * R2;
	m = R1 + R2;
	float Vout = j / m;
	int size = sqrt(Vout);
	int* arr = new int[size] {}; //소인수 저장용 배열 동적할당

	/*소인수 구하기*/
	for (int i = 2; i <= size; i++) {
		while ((int)Vout % i == 0) {
			arr[k++] = i; //소인수 저장
		}
	}
	int t = k;
	if (Vout != 1) {
		arr[t] = Vout;
	}

	/*순환소수 검사*/
	int g = 0;
	for (int i = 0; i<=t; i++) {
		while (arr[i] == 2 || arr[i] == 5) {
			g++;
		}
	}
	if (g == t+1) { //마지막까지 소인수가 전부 2나 5뿐인 경우: 유한소수
		cout << "Vout: " << j << '/' << m << " = " << Vout << endl;
	}
	else { //그 외의 소인수가 있어 배열 검사가 일찍 끝난 경우: 순환소수
		/*
		int mod = 0, n=1;
		mod = 10 % (int)Vout;
		char str[30];
		str[0] = mod;
		while (1) {
			mod = mod * 10 / Vout;
			str[n++] = mod;
			for (int i = 0; str[i] != NULL; i++) {
				for (int q = 0; str[q] != NULL; q++) {
					if (str[i] == str[q]) {
						break;
					}
				}
			}
		}
		char s = str[n-1];
		*/
		cout << "Vout: " << j << '/' << m << " = " << Vout << "(.순환)" << endl;
	}

	delete[] arr;
}

int gcd(int mR, int R1)
{
	int t;
	while (R1 != 0) {
		t = mR % R1;
		mR = R1;
		R1 = t;
	}
	return mR;
}
int lcm(int mR, int R1)
{
	return (mR * R1) / gcd(mR, R1);
}

/*병렬 회로 계산*/
void Parallel (int Vs, int R1, int R2, int RL)
{
	int m = 0, j = 0; //분모, 분자
	int Pr = (R2*RL)/(R2+RL); //병렬 저항
	int mR = R2 + RL;//병렬 저항식의 분모

	int l = lcm(mR, R1); //병렬 저항의 분모와 R1의 최소공배수 구함
	int a = l / mR;//통분 변수 (최소공배수를 병렬저항식의 분모로 나눔)
	
	j = l * Vs * ((R2 * RL) / mR); //최종 분자
	m = (a * R2 * RL) + (l * R1); //최종 분모

	float Vout = j / m;
	int size = sqrt(Vout);
	if (size < 2) {
		size++;
	}
	int* arr2 = new int[size] {}; //소인수 저장용 배열 동적할당
	
	float PL = 100*Vout * ((R2 * (Vs / R1 + Pr)) / (R2 + RL));
	float Ps = Vs * (Vs / (R1 + Pr));

	/*소인수 구하기
	int k = 0;
	for (int i = 2; i <= size; i++) {
		while ((int)Vout % i == 0) {
			arr2[k] = i; //소인수 저장
			k++;
		}
	}
	int t = k;
	if (Vout != 1) {
		arr2[t] = Vout;
	}

	//순환소수 검사
	int g = 0;
	for (int i = 0; i <= t; i++) {
		while (arr2[i] == 2 || arr2[i] == 5) {
			g++;
		}
	}
	if (g == t) { //마지막까지 소인수가 전부 2나 5뿐인 경우: 유한소수
		cout << "Vout: " << j << '/' << m << " = " << Vout << endl;
	}
	else { //그 외의 소인수가 있어 배열 검사가 일찍 끝난 경우: 순환소수
		cout << "Vout: " << j << '/' << m << " = " << Vout << "(. 순환)" << endl;
	}
	*/
	cout << "Vout: " << j << '/' << m << " = " << Vout << endl;
	printf("Load power ratio: %.1f%%", PL / Ps);
	delete[] arr2;
}

int main()
{
	int Vs, R1, R2, RL; //입력 받을 전압과 저항
	cout << "Vs: "; cin >> Vs;
	cout << "R1: "; cin >> R1;
	cout << "R2: "; cin >> R2;
	cout << "R(Load): "; cin >> RL;
	cout << endl;

	if (RL == 0) { //직렬 회로인 경우
		Series(Vs, R1, R2);
	}
	else { //병렬 회로인 경우
		Parallel(Vs, R1, R2, RL);
	}

	return 0;
}