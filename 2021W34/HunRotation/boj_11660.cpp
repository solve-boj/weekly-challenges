/*
    구간 합 구하기 5
    https://www.acmicpc.net/problem/11660
*/

#include <cstdio>

using namespace std;

int arr[1025][1025];
int sum[1025][1025];
int N, M;

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            scanf("%d", &arr[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + arr[i][j] - sum[i-1][j-1];
        }
    }
    for(int i=0;i<M;i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
    }
}


// keyword: DP
// 시간복잡도: O(N^2)
/*
idea: 순서대로 표 내 값을 입력할 때 (1, 1)에서 (x, y)까지 합을 저장한
sum 배열의 값을 채움
*/