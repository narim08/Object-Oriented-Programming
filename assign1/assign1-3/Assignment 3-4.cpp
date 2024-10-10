#include <iostream>
#include <cstdlib>
using namespace std;


/*Insertion sort: 두번째 값부터 시작하여 앞의 배열 중 알맞은 위치로 삽입되는 정렬 방법*/
void InsertionOne(int list[], int current)
{
	bool located = false;
	int temp = list[current];
	int w;
	for (w = current - 1; w >= 0 && !located;) {
		if (temp < list[w]) { //현재 walker가 temp보다 큰 경우
			list[w + 1] = list[w]; //다음 칸을 walker로 설정
			w--;
		}
		else {
			located = true;
		}
	}
	list[w + 1] = temp;
	return;
}
void InsertionSort(int list[], int last)
{
	for (int current = 1; current <= last; current++) { //두번째칸부터 실행
		InsertionOne(list, current);
	}
}


/*quick sort: pivot값을 기준으로 양측 분할로 각각 값을 비교하여 정렬하는 방법*/
void QuickSort(int list[], int current, int last)
{
	int pivot = current;
	int left = pivot + 1; //pivot 다음 칸부터 왼쪽으로 검사할 변수(pivot보다 처음으로 큰 값 찾음)
	int right = last; //마지막 칸부터 오른쪽으로 검사할 변수(pivot보다 처음으로 작은 값 찾음)
	int temp;

	if (current >= last) { //해당 구역에서 정렬 끝나면 종료시킴
		return;
	}

	while (left <= right) { //서로 위치가 순서대로 있을 경우에 반복
		for (left = pivot + 1; left <= last && list[left] <= list[pivot];) {
			left++;
		}
		for (right = last; right > current && list[right] >= list[pivot];) {
			right--;
		}

		/*변수들의 위치가 서로 바뀔 경우 pivot과 right(작은 값)을 교환하여 정렬*/
		if (left > right) {
			temp = list[right];
			list[right] = list[pivot];
			list[pivot] = temp;
		}
		/*변수들의 위치가 순서대로일 경우 left(큰 값)와 right(작은 값)을 교환하여 정렬*/
		else {
			temp = list[left];
			list[left] = list[right];
			list[right] = temp;
		}
	}

	/*분할하여 재귀적 호출로 반복하여 계산*/
	QuickSort(list, current, right - 1); //처음부터 작은 값 전까지 (pivot 제외)
	QuickSort(list, right+1, last); //작은 값 다음부터 마지막까지
}


/*merge Sort: 절반으로 계속 나누다가 2개씩 남는 시점부터 합치면서 정렬하는 방법*/
void MergeOne(int list[], int first, int m, int last)
{
	int f = first;
	int i = first;
	int M = m + 1;

	int* arr = new int[last + 1]{}; //정렬된 list를 저장할 새 배열 동적 할당

	while (f <= m && M <= last) {
		if (list[f] <= list[M]) { //정렬된 상태일 경우
			arr[i++] = list[f++]; //새 배열에 그 값을 저장
		}
		else { //정렬이 필요한 경우
			arr[i++] = list[M++]; //새 배열에 작은 값 먼저 저장
		}
	}

	if (f > m) {
		for (int j = M; j <= last; j++) {
			arr[i++] = list[j];
		}
	}
	else {
		for (int j = f; j <= m; j++) {
			arr[i++] = list[j];
		}
	}

	/*정렬된 배열을 다시 원래 배열에 저장*/
	for (int j = first; j <= last; j++) {
		list[j] = arr[j];
	}

	delete[] arr; //정렬용 배열 동적할당 해제
}
void MergeSort(int list[], int first, int last)
{
	if (first < last) {
		int m = (first + last) / 2; //중간 값 계산

		/*분할하여 재귀적 호출로 반복하여 계산*/
		MergeSort(list, first, m); //좌측
		MergeSort(list, m + 1, last); //우측
		MergeOne(list, first, m, last);
	}
}

/*Bubble Sort: 끝에서부터 비교하여 앞 수가 더 클 경우 위치를 교환하여 정렬하는 방법*/
void BubbleUp(int list[], int current, int last)
{
	for (int w = last; w > current; w--) { //마지막부터 앞 칸과 비교하여 정렬
		if (list[w] < list[w - 1]) { 
			int temp = list[w];
			list[w] = list[w - 1];
			list[w - 1] = temp;
		}
	}
	return;
}
void BubbleSort(int list[], int last) { //배열의 정렬이 끝날 때까지 반복, 함수 호출
	for (int current = 0; current < last; current++) {
		BubbleUp(list, current, last);
	}
}


int main()
{
	//clock_t start, end;
	int size; //list 사이즈
	cin >> size;

	int* list = new int[size]; //입력받은 size만큼 배열 동적할당
	
	for (int i = 0; i < size; i++) {
		cin >> list[i];
	}
	cout << endl;
	/*
	for (int i = 0; i < size; i++) {
		list[i] = rand() % 100;
	}
	start = clock();
	InsertionSort(list, size - 1);
	end = clock();
	*/

	InsertionSort(list, size - 1);
	//QuickSort(list, 0, size - 1);
	//MergeSort(list, 0, size - 1);
	//BubbleSort(list, size - 1); 
	
	
	cout << "Sorted order: ";
	for (int i = 0; i < size; i++) {
		cout << list[i] << ' ';
	}
	cout << endl;
	cout << "Median number: " << list[size / 2] << endl;
	
	//cout << "sorting time: " << (double)(end - start) / CLOCKS_PER_SEC;

	delete[]list; //배열 할당 해제
	return 0;
}