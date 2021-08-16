/*
    구간 합 구하기 5
    https://www.acmicpc.net/problem/11660
*/
#include <cstdio>

int table[1024][1024];
int sum[1025][1025];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &table[i][j]);
            sum[i+1][j+1] = table[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
        }
    }

    int x1, y1, x2, y2;
    for(int i=0; i<m; ++i){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
    }
    return 0;
}
/*
    간단한 2차원 부분합 배열 문제
*/