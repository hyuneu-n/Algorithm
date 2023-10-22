#include <iostream> //����� �������
#include <algorithm> //min�Լ��� ����ϱ� ���� �������
#include <string> //���ڿ� �������
using namespace std;

void ShowMatrix(int** E, string S, string T, int m, int n); //�����Ÿ��� �������迭�� ����Լ�
void CalculateD(string S, string T, int m, int n, int** E); //�����Ÿ��� ����ϴ� �Լ�

int main() {
	string S, T; //���ڿ� S, T ����

	//S, T �Է¹ޱ�
	cout << "\tSOURCE [IN] >> ";
	cin >> S;
	cout << "\tTARGET [IN] >> ";
	cin >> T;
	cout << endl;

	int m = S.length(); //S ���ڿ� ����
	int n = T.length(); //T ���ڿ� ����

	int** E = new int* [m + 1]; //�������迭 ��(column) �����Ҵ�
	for (int i = 0; i <= m; i++)
		E[i] = new int[n + 1]; //�������迭 ��(row) �����Ҵ�

	CalculateD(S, T, m, n, E); //�����Ÿ���� �Լ� ȣ��
	ShowMatrix(E, S, T, m, n); //�����Ÿ� �������迭 ����Լ� ȣ��
}

//�����Ÿ��� ����ϴ� �Լ�
void CalculateD(string S, string T, int m, int n, int** E) {
	//���ڿ��� ���� ��� �������迭 �ʱ�ȭ
	for (int i = 0; i <= m; i++)
		E[i][0] = i;
	for (int j = 1; j <= n; j++)
		E[0][j] = j;

	//�����Ÿ� ���
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (S[i - 1] == T[j - 1]) //�밢�� ������ ���ʿ��� ���
				E[i][j] = min({ E[i][j - 1] + 1,E[i - 1][j] + 1,E[i - 1][j - 1] });
			else //�밢�� ���꿡�� substitute������ �ʿ��� ���
				E[i][j] = min({ E[i][j - 1] + 1,E[i - 1][j] + 1,E[i - 1][j - 1] + 1 });
		}
	}
}
//���� �Ÿ��� �������迭�� ����ϴ� �Լ� 
void ShowMatrix(int** E, string S, string T, int m, int n) {

	cout << "\t  " << S << " �� " << T << endl;
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