<<<<<<< HEAD
#include <iostream>
#include <cmath>
using namespace std;

void MergeSort(int *A, int p, int q) {
	if (p < q) {
		int k = floor((p + q) / 2); //바닥함수
		MergeSort(A, p, k); //A[p]부터 A[k]까지 합병정렬
		MergeSort(A, k + 1, q); //A[k + 1]부터 A[q]까지 합병정렬

		int B[8] = { 0, }; //새로운 배열 B 선언 및 초기화
		int a = p;
		int b = k + 1;

		for (int i = p; i <= q; i++) {
			if (a == k + 1) { //왼쪽 다 썼을 때
				B[i] = A[b];
				b++;
			}
			else if (b == q + 1) { //오른쪽 다 썼을 때?
				B[i] = A[a];
				a++;
			}
			else {
				if (A[a] < A[b]) {
					B[i] = A[a];
					a++;
				}
				else {
					B[i] = A[b];
					b++;
				}
			}
		}
		for (int i = p; i <= q; i++)
			A[i] = B[i];
	}
}

int main() {
	int A[8] = { 37,10,22,30,35,13,25,24 };
	
	MergeSort(A, 0, 7);

	cout << "Sorted A = [ ";
	for (int i = 0; i < 8; i++)
		cout << A[i] << ' ';
	cout << "]\n";
}
=======
#include <iostream>
#include <cmath>
using namespace std;

void MergeSort(int *A, int p, int q) {
	if (p < q) {
		int k = floor((p + q) / 2); //바닥함수
		MergeSort(A, p, k); //A[p]부터 A[k]까지 합병정렬
		MergeSort(A, k + 1, q); //A[k + 1]부터 A[q]까지 합병정렬

		int B[8] = { 0, }; //새로운 배열 B 선언 및 초기화
		int a = p;
		int b = k + 1;

		for (int i = p; i <= q; i++) {
			if (a == k + 1) { //왼쪽 다 썼을 때
				B[i] = A[b];
				b++;
			}
			else if (b == q + 1) { //오른쪽 다 썼을 때?
				B[i] = A[a];
				a++;
			}
			else {
				if (A[a] < A[b]) {
					B[i] = A[a];
					a++;
				}
				else {
					B[i] = A[b];
					b++;
				}
			}
		}
		for (int i = p; i <= q; i++)
			A[i] = B[i];
	}
}

int main() {
	int A[8] = { 37,10,22,30,35,13,25,24 };
	
	MergeSort(A, 0, 7);

	cout << "Sorted A = [ ";
	for (int i = 0; i < 8; i++)
		cout << A[i] << ' ';
	cout << "]\n";
}
>>>>>>> 18e644b (Sort)
