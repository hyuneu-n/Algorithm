#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void ShowList(int* A, int left, int right) {
	cout << "[ ";
	for (int i = left; i <= right; i++)
		cout << A[i] << ' ';
	cout << "]\n";
}

void QuickSort(int* A, int left, int right) {
	if (left < right) {
		cout << "LEFT = " << left << endl;
		cout << "RIGHT = " << right << endl;
		int pivot = rand() % (right - left + 1) + left;

		cout << "PIVOT INDEX = " << pivot << endl;
		cout << "PIVOT VALUE = " << A[pivot] << endl;

		swap(A[left], A[pivot]);

		//Pivot보다 작은 수 왼쪽으로 정렬

		int i = left + 1;
		int j = right;

		while (i < j) {
			if (A[i] < A[left]) {
				i++;
				continue;
			}
			while (A[j] > A[left]) {
				j--;
				if (i == j)
					break;
			}
			swap(A[i], A[j]);
			i++;
		}
		//pivot 적재적소에 배치
		int k = right;

		while (A[k] > A[left])
			k--;
		swap(A[k], A[left]);
		pivot = k;

		cout << "LAST PIVOT INDEX = " << pivot << endl;

		ShowList(A, left, right);
		cout << "================================\n";
		QuickSort(A, left, pivot - 1);
		QuickSort(A, pivot + 1, right);
	}	
}

int main() {
	srand((unsigned)time(NULL));

	int A[12] = { 6,3,11,9,12,2,8,15,18,10,7,14 };
	QuickSort(A, 0, 11);

	cout << "결과 = ";
	ShowList(A, 0, 11);
}