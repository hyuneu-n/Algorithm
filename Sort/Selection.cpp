#include <iostream> //입출력 헤더파일
#include <cstdlib> //난수생성을 위한 헤더파일
#include <ctime> //난수생성을 위한 헤더파일
#include <algorithm> //swap함수 사용을 위한 헤더파일
using namespace std;

int Selection(int* A, int left, int right, int k); //선택문제 함수 원형
void QuickSort(int* A, int left, int right); //퀵정렬 함수 원형

int main() {
	srand((unsigned)time(NULL)); //seed값 부여

	int A[1000]; //임의 정수 1000개를 저장할 배열 A 선언

	for (int i = 0; i < 1000; i++) { //임의 정수 1000개 생성
		A[i] = rand();

		//임의 생성된 정수 1000개 중 중복이 있는지 확인
		int j = 0;
		for (;;) { //무한루프로 중복 확인
			if (A[i] == A[j]) { //중복이 존재하는 경우
				A[i] = rand(); //임의 정수 재생성
				j = -1;
			}
			j++;
			if (j == i) //중복된 수가 없는 경우
				break; //무한루프 탈출
		}
	}
	//검증
	int B[1000]; //퀵정렬을 이용해 검증할 배열 B 선언
	for (int i = 0; i < 1000; i++)
		B[i] = A[i];

	//732번째 작은 수 출력
	int k = 732;
	cout << k << "번째 작은 수는 [ " << Selection(A, 0, 999, k) << " ] 입니다" << endl << endl;

	//배열 B 크기 순으로 정렬
	QuickSort(B, 0, 999);

	//732번째로 작은 수 근처 값 출력
	cout << "[ 1000개의 원소 오름차순 정렬 ]" << endl << endl;
	for (int i = k-3; i <= k+2; i++)
		cout << i+1 << "번째 작은 수 << " << B[i] << endl;
}

int Selection(int* A, int left, int right, int k) {
	int pivot = rand() % (right - left + 1) + left;  //A[left]~A[right] 범위에서 pivot 랜덤 결정

	swap(A[left], A[pivot]);  //pivot 인덱스와 가장 왼쪽 인덱스 교환

	//pivot 기준 작은 수는 왼쪽으로, 큰 수는 오른쪽으로 배치
	int i = left + 1;  //left+1 인덱스 값부터 pivot과 비교
	int j = right;
	while (i < j) {
		if (A[i] < A[left]) { //A[left]=pivot이므로 원소가 pivot보다 작은 경우
			i++;
			continue;
		}
		while (A[j] > A[left]) { //원소가 pivot보다 큰 경우
			j--; //가장 오른쪽 인덱스부터 왼쪽으로 순차적으로 비교하여 pivot보다 작은 원소를 갖는 인덱스 서치
			if (j == i)  //서치된 값이 존재하지 않는 경우
				break;
		}
		swap(A[i], A[j]);  //두 값의 자리 교환
		i++;
	}

	//pivot을 기준으로 나눈 Small Group과 Large Group 사이에 pivot 배치
	int l = right;
	while (A[l] > A[left]) //가장 오른쪽 인덱스 원소부터 pivot과 비교하여 pivot보다 큰 경우 
		l--; //변동 없음
	swap(A[l], A[left]); //pivot보다 작은 경우 pivot과 A[l] 자리 교환
	pivot = l; //새로운 pivot 설정

	int Small_Group = (pivot - 1) - left + 1; //Small group의 크기

	if (k <= Small_Group)
		Selection(A, left, pivot - 1, k);  //Small group에 k번째 작은 수가 존재하는 경우
	else if (k == Small_Group + 1)  //pivot이 k번째 작은 수인 경우
		return A[pivot];
	else   //Large group에 k번째 작은 수가 존재하는 경우 
		Selection(A, pivot + 1, right, k - Small_Group - 1);
}

void QuickSort(int* A, int left, int right) {
	if (left < right) {
		int pivot = rand() % (right - left + 1) + left;  //pivot 랜덤 결정
		swap(A[left], A[pivot]);

		//pivot 기준 작은 수는 왼쪽으로, 큰 수는 오른쪽으로 배치
		//Selection 알고리즘과 동일
		int i = left + 1;
		int j = right;
		while (i < j) {
			if (A[i] < A[left]) {
				i++;
				continue;
			}
			while (A[j] > A[left]) {
				j--;
				if (j == i)
					break;
			}
			swap(A[i], A[j]);
			i++;
		}

		//pivot을 기준으로 나눈 Small Group과 Large Group 사이에 pivot 배치
		//Selection 알고리즘과 동일
		int k = right;
		while (A[k] > A[left])
			k--;
		swap(A[k], A[left]);
		pivot = k;

		QuickSort(A, left, pivot - 1);
		QuickSort(A, pivot + 1, right);
	}
}