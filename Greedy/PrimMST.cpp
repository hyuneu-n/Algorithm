#include <iostream> //입출력 헤더파일
#include <algorithm> //min함수를 사용하기 위한 헤더파일
#include <climits> //정수 데이터 타입의 최대값(INT_MAX)을 포함하는 헤더 파일
using namespace std;

const int INF = INT_MAX; //무한대를 정수 데이터 타입(INT_MAX)의 최댓값으로 정의

void PrimMST(int(*G)[6], int(*T)[6]); //MST를 만드는 함수를 선언
void ShowMatrix(int(*G)[6]); //인접행렬을 출력하는 함수를 선언
void ShowD(int* D); //배열 D를 출력하는 함수를 선언

int main() {
    int Graph[6][6] = { {0, 8, INF, 2, 4, INF}, //그래프의 인접 행렬 정의
                        {8, 0, 1, 4, INF, 2},
                        {INF, 1, 0, INF, INF, 1},
                        {2, 4, INF, 0, 3, 7},
                        {4, INF, INF, 3, 0, 9},
                        {INF, 2, 1, 7, 9, 0} };

    int T[6][6] = { 0, }; //MST의 인접 행렬 T 초기화
    fill(&T[0][0], &T[5][6], INF); //T를 무한대(INF)로 채움

    PrimMST(Graph, T); //Prim 알고리즘을 사용하여 MST 생성
    cout << "\t\tRESULT\n\n"; 
    ShowMatrix(T); //MST의 인접 행렬 출력
    cout << "\n====================================\n\n";
}

void PrimMST(int(*G)[6], int(*T)[6]) {
    int p = 4; //'e'를 시작 정점으로 선택
    T[p][p] = 0; //MST의 시작 정점 초기화

    //현재 정점과 정점을 연결하는 간선의 최소가중치를 저장하는 배열 D 선언
    int D[6] = { 0, }; //배열 D 초기화
    for (int i = 0; i < 6; i++)
        D[i] = G[p][i]; //배열 D를 시작 정점과의 가중치로 초기화

    //MST를 만든다
    int k = 0;

    while (k < 5) { //6개의 정점 중 5개를 선택하면 MST 완성
        int minV = INF; //최소 가중치를 가진 간선의 가중치
        int minV_index = 0; //최소 가중치를 가진 간선의 목적지 정점

        for (int i = 0; i < 6; i++) {
            if (D[i] != 0)
                if (D[i] < minV) {
                    minV = D[i]; //현재까지의 최소 가중치 갱신
                    minV_index = i; //최소 가중치를 가진 간선의 목적지 정점 갱신
                }
        }
        ShowD(D); //배열 D 출력
        

        T[minV_index][minV_index] = 0; //선택한 정점을 MST에 추가

        int minE = INF;
        int minE_index = 0;

        for (int i = 0; i < 6; i++) {
            if (D[i] == 0)
                if (G[minV_index][i] < minE) {
                    minE = G[minV_index][i]; //최소 가중치를 가진 간선의 가중치 갱신
                    minE_index = i; //최소 가중치를 가진 간선의 목적지 정점 갱신
                }
        }

        cout << "   ADD : Vertex(" << char(97 + minV_index) << "), ";
        cout << "Edge(" << minV_index << "," << minE_index << ")\n\n";

        T[minV_index][minE_index] = minE; //MST에 간선 추가
        T[minE_index][minV_index] = minE; //MST에 간선 추가

        ShowMatrix(T);

        for (int i = 0; i < 6; i++) {
            if (G[minV_index][i] < D[i])
                D[i] = G[minV_index][i]; //배열 D 갱신
        }
        k++; //MST에 추가된 정점 수 증가
    }
    ShowD(D); //마지막으로 갱신된 배열 D 출력
}

void ShowMatrix(int(*T)[6]) {
    cout << "      a    b    c    d    e    f" << endl;
    cout << "     [0]  [1]  [2]  [3]  [4]  [5]" << endl;

    for (int i = 0; i < 6; i++) {
        cout << char(97 + i) << " [" << i << "]";
        for (int j = 0; j < 6; j++) {
            if (T[i][j] == INF)
                cout << " ∞   "; //무한대(INF)는 "∞"로 출력
            else
                cout << " " << T[i][j] << "   "; //MST의 가중치 출력
        }
        cout << endl;
    }
}

void ShowD(int* D) {
    cout << endl;
    cout << "   Updated D = [ ";
    for (int i = 0; i < 6; i++) {
        if (D[i] == INF)
            cout << "∞ "; //무한대(INF)는 "∞"로 출력
        else
            cout << D[i] << ' ';
    }
    cout << "]\n\n";
    cout << "====================================\n\n";
}
