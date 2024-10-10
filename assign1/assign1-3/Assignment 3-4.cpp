#include <iostream>
#include <cstdlib>
using namespace std;


/*Insertion sort: �ι�° ������ �����Ͽ� ���� �迭 �� �˸��� ��ġ�� ���ԵǴ� ���� ���*/
void InsertionOne(int list[], int current)
{
	bool located = false;
	int temp = list[current];
	int w;
	for (w = current - 1; w >= 0 && !located;) {
		if (temp < list[w]) { //���� walker�� temp���� ū ���
			list[w + 1] = list[w]; //���� ĭ�� walker�� ����
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
	for (int current = 1; current <= last; current++) { //�ι�°ĭ���� ����
		InsertionOne(list, current);
	}
}


/*quick sort: pivot���� �������� ���� ���ҷ� ���� ���� ���Ͽ� �����ϴ� ���*/
void QuickSort(int list[], int current, int last)
{
	int pivot = current;
	int left = pivot + 1; //pivot ���� ĭ���� �������� �˻��� ����(pivot���� ó������ ū �� ã��)
	int right = last; //������ ĭ���� ���������� �˻��� ����(pivot���� ó������ ���� �� ã��)
	int temp;

	if (current >= last) { //�ش� �������� ���� ������ �����Ŵ
		return;
	}

	while (left <= right) { //���� ��ġ�� ������� ���� ��쿡 �ݺ�
		for (left = pivot + 1; left <= last && list[left] <= list[pivot];) {
			left++;
		}
		for (right = last; right > current && list[right] >= list[pivot];) {
			right--;
		}

		/*�������� ��ġ�� ���� �ٲ� ��� pivot�� right(���� ��)�� ��ȯ�Ͽ� ����*/
		if (left > right) {
			temp = list[right];
			list[right] = list[pivot];
			list[pivot] = temp;
		}
		/*�������� ��ġ�� ��������� ��� left(ū ��)�� right(���� ��)�� ��ȯ�Ͽ� ����*/
		else {
			temp = list[left];
			list[left] = list[right];
			list[right] = temp;
		}
	}

	/*�����Ͽ� ����� ȣ��� �ݺ��Ͽ� ���*/
	QuickSort(list, current, right - 1); //ó������ ���� �� ������ (pivot ����)
	QuickSort(list, right+1, last); //���� �� �������� ����������
}


/*merge Sort: �������� ��� �����ٰ� 2���� ���� �������� ��ġ�鼭 �����ϴ� ���*/
void MergeOne(int list[], int first, int m, int last)
{
	int f = first;
	int i = first;
	int M = m + 1;

	int* arr = new int[last + 1]{}; //���ĵ� list�� ������ �� �迭 ���� �Ҵ�

	while (f <= m && M <= last) {
		if (list[f] <= list[M]) { //���ĵ� ������ ���
			arr[i++] = list[f++]; //�� �迭�� �� ���� ����
		}
		else { //������ �ʿ��� ���
			arr[i++] = list[M++]; //�� �迭�� ���� �� ���� ����
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

	/*���ĵ� �迭�� �ٽ� ���� �迭�� ����*/
	for (int j = first; j <= last; j++) {
		list[j] = arr[j];
	}

	delete[] arr; //���Ŀ� �迭 �����Ҵ� ����
}
void MergeSort(int list[], int first, int last)
{
	if (first < last) {
		int m = (first + last) / 2; //�߰� �� ���

		/*�����Ͽ� ����� ȣ��� �ݺ��Ͽ� ���*/
		MergeSort(list, first, m); //����
		MergeSort(list, m + 1, last); //����
		MergeOne(list, first, m, last);
	}
}

/*Bubble Sort: ���������� ���Ͽ� �� ���� �� Ŭ ��� ��ġ�� ��ȯ�Ͽ� �����ϴ� ���*/
void BubbleUp(int list[], int current, int last)
{
	for (int w = last; w > current; w--) { //���������� �� ĭ�� ���Ͽ� ����
		if (list[w] < list[w - 1]) { 
			int temp = list[w];
			list[w] = list[w - 1];
			list[w - 1] = temp;
		}
	}
	return;
}
void BubbleSort(int list[], int last) { //�迭�� ������ ���� ������ �ݺ�, �Լ� ȣ��
	for (int current = 0; current < last; current++) {
		BubbleUp(list, current, last);
	}
}


int main()
{
	//clock_t start, end;
	int size; //list ������
	cin >> size;

	int* list = new int[size]; //�Է¹��� size��ŭ �迭 �����Ҵ�
	
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

	delete[]list; //�迭 �Ҵ� ����
	return 0;
}