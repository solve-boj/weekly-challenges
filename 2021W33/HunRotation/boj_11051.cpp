/*
    이항 계수 2
    https://www.acmicpc.net/problem/11051
*/

#include <cstdio>

using namespace std;

int N, K;
int dp[1001][1001];

int nCk(int n, int k) {
    if(n==1 || k==0) return 1;
    if(n==k) return 1;
    if(dp[n][k]) return dp[n][k];
    return dp[n][k] = (nCk(n-1, k) + nCk(n-1, k-1)) % 10007;
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", nCk(N, K));
}

// keyword: DP
// 시간복잡도: O(N)
/*
idea: 말 그대로 조합의 성질
*/