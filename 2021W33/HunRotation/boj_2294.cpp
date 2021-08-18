/*
    동전 2
    https://www.acmicpc.net/problem/2294
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, cost[101], dp[101][10001];
const int INF = 1000000000;

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) {
        scanf("%d", &cost[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<=k;j++) {
            dp[i][j] = INF;
        }
    } 
    for(int i=0;i<n;i++) {
        dp[i][0] = 0;
        for(int j=0;j<=k;j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            int j_ = j + cost[i];
            if(j_ <= k) dp[i][j_] = min(dp[i][j] + 1, dp[i][j_]); 
        }
    }

    printf("%d", (dp[n-1][k] == INF)?(-1):(dp[n-1][k]));
}

// keyword: DP
// 시간복잡도: O(NK)
/*
idea: dp[n][k]는 n번 동전 포함 그 이후의 동전만 사용시
k원 표현할 수 있는 동전의 최소 개수
bottom-up 방식
*/