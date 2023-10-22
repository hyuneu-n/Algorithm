#include <iostream> //����� �������
#include <algorithm> //min�Լ��� ����ϱ� ���� �������
#include <climits> //���� ������ Ÿ���� �ִ밪(INT_MAX)�� �����ϴ� ��� ����
using namespace std;

const int INF = INT_MAX; //���Ѵ븦 ���� ������ Ÿ��(INT_MAX)�� �ִ����� ����

void PrimMST(int(*G)[6], int(*T)[6]); //MST�� ����� �Լ��� ����
void ShowMatrix(int(*G)[6]); //��������� ����ϴ� �Լ��� ����
void ShowD(int* D); //�迭 D�� ����ϴ� �Լ��� ����

int main() {
    int Graph[6][6] = { {0, 8, INF, 2, 4, INF}, //�׷����� ���� ��� ����
                        {8, 0, 1, 4, INF, 2},
                        {INF, 1, 0, INF, INF, 1},
                        {2, 4, INF, 0, 3, 7},
                        {4, INF, INF, 3, 0, 9},
                        {INF, 2, 1, 7, 9, 0} };

    int T[6][6] = { 0, }; //MST�� ���� ��� T �ʱ�ȭ
    fill(&T[0][0], &T[5][6], INF); //T�� ���Ѵ�(INF)�� ä��

    PrimMST(Graph, T); //Prim �˰����� ����Ͽ� MST ����
    cout << "\t\tRESULT\n\n"; 
    ShowMatrix(T); //MST�� ���� ��� ���
    cout << "\n====================================\n\n";
}

void PrimMST(int(*G)[6], int(*T)[6]) {
    int p = 4; //'e'�� ���� �������� ����
    T[p][p] = 0; //MST�� ���� ���� �ʱ�ȭ

    //���� ������ ������ �����ϴ� ������ �ּҰ���ġ�� �����ϴ� �迭 D ����
    int D[6] = { 0, }; //�迭 D �ʱ�ȭ
    for (int i = 0; i < 6; i++)
        D[i] = G[p][i]; //�迭 D�� ���� �������� ����ġ�� �ʱ�ȭ

    //MST�� �����
    int k = 0;

    while (k < 5) { //6���� ���� �� 5���� �����ϸ� MST �ϼ�
        int minV = INF; //�ּ� ����ġ�� ���� ������ ����ġ
        int minV_index = 0; //�ּ� ����ġ�� ���� ������ ������ ����

        for (int i = 0; i < 6; i++) {
            if (D[i] != 0)
                if (D[i] < minV) {
                    minV = D[i]; //��������� �ּ� ����ġ ����
                    minV_index = i; //�ּ� ����ġ�� ���� ������ ������ ���� ����
                }
        }
        ShowD(D); //�迭 D ���
        

        T[minV_index][minV_index] = 0; //������ ������ MST�� �߰�

        int minE = INF;
        int minE_index = 0;

        for (int i = 0; i < 6; i++) {
            if (D[i] == 0)
                if (G[minV_index][i] < minE) {
                    minE = G[minV_index][i]; //�ּ� ����ġ�� ���� ������ ����ġ ����
                    minE_index = i; //�ּ� ����ġ�� ���� ������ ������ ���� ����
                }
        }

        cout << "   ADD : Vertex(" << char(97 + minV_index) << "), ";
        cout << "Edge(" << minV_index << "," << minE_index << ")\n\n";

        T[minV_index][minE_index] = minE; //MST�� ���� �߰�
        T[minE_index][minV_index] = minE; //MST�� ���� �߰�

        ShowMatrix(T);

        for (int i = 0; i < 6; i++) {
            if (G[minV_index][i] < D[i])
                D[i] = G[minV_index][i]; //�迭 D ����
        }
        k++; //MST�� �߰��� ���� �� ����
    }
    ShowD(D); //���������� ���ŵ� �迭 D ���
}

void ShowMatrix(int(*T)[6]) {
    cout << "      a    b    c    d    e    f" << endl;
    cout << "     [0]  [1]  [2]  [3]  [4]  [5]" << endl;

    for (int i = 0; i < 6; i++) {
        cout << char(97 + i) << " [" << i << "]";
        for (int j = 0; j < 6; j++) {
            if (T[i][j] == INF)
                cout << " ��   "; //���Ѵ�(INF)�� "��"�� ���
            else
                cout << " " << T[i][j] << "   "; //MST�� ����ġ ���
        }
        cout << endl;
    }
}

void ShowD(int* D) {
    cout << endl;
    cout << "   Updated D = [ ";
    for (int i = 0; i < 6; i++) {
        if (D[i] == INF)
            cout << "�� "; //���Ѵ�(INF)�� "��"�� ���
        else
            cout << D[i] << ' ';
    }
    cout << "]\n\n";
    cout << "====================================\n\n";
}
