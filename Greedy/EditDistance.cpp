#include <iostream> //입출력 헤더파일
#include <algorithm> //min함수를 사용하기 위한 헤더파일
#include <string> //문자열 헤더파일
using namespace std;

void ShowMatrix(int** E, string S, string T, int m, int n); //편집거리를 이차원배열로 출력함수
void CalculateD(string S, string T, int m, int n, int** E); //편집거리를 계산하는 함수

int main() {
	string S, T; //문자열 S, T 선언

	//S, T 입력받기
	cout << "\tSOURCE [IN] >> ";
	cin >> S;
	cout << "\tTARGET [IN] >> ";
	cin >> T;
	cout << endl;

	int m = S.length(); //S 문자열 개수
	int n = T.length(); //T 문자열 개수

	int** E = new int* [m + 1]; //이차원배열 열(column) 동적할당
	for (int i = 0; i <= m; i++)
		E[i] = new int[n + 1]; //이차원배열 행(row) 동적할당

	CalculateD(S, T, m, n, E); //편집거리계산 함수 호출
	ShowMatrix(E, S, T, m, n); //편집거리 이차원배열 출력함수 호출
}

//편집거리를 계산하는 함수
void CalculateD(string S, string T, int m, int n, int** E) {
	//문자열이 없는 경우 이차원배열 초기화
	for (int i = 0; i <= m; i++)
		E[i][0] = i;
	for (int j = 1; j <= n; j++)
		E[0][j] = j;

	//편집거리 계산
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (S[i - 1] == T[j - 1]) //대각선 연산이 불필요한 경우
				E[i][j] = min({ E[i][j - 1] + 1,E[i - 1][j] + 1,E[i - 1][j - 1] });
			else //대각선 연산에서 substitute연산이 필요한 경우
				E[i][j] = min({ E[i][j - 1] + 1,E[i - 1][j] + 1,E[i - 1][j - 1] + 1 });
		}
	}
}
//편집 거리를 이차원배열로 출력하는 함수 
void ShowMatrix(int** E, string S, string T, int m, int n) {

	cout << "\t  " << S << " ▶ " << T << endl;
	cout << endl << "\t  ";
	for (int i = 0; i <= n; i++)
		cout << T[i] << "   ";
	cout << endl << "     ";
	for (int i = 0; i <= n; i++)
		cout << "[" << i << "] ";
	cout << endl;

	for (int i = 0; i <= m; i++) {
		if (i == 0)
			cout << "  [" << i << "] ";
		else
			cout << S[i - 1] << " [" << i << "] ";
		for (int j = 0; j <= n; j++) {
			cout << E[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "\t EDIT DISTANCE = " << E[m][n] << endl;
}