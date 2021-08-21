/*
    쉬운 계단 수
    https://www.acmicpc.net/problem/10844
*/

#include <cstdio>

using namespace std;

int N;
int dp[101][10];

int f(int x, int first) {
    if (x==1) return 1;
    if (dp[x][first]) return dp[x][first];
    if (first==0) return f(x-1, 1);
    if (first==9) return f(x-1, 8);
    return dp[x][first] = (f(x-1, first+1) + f(x-1, first-1)) % 1000000000;
}

int main() {
    int res = 0;
    scanf("%d", &N);
    for(int i=1;i<=9;i++) {
        res = (res + f(N, i)) % 1000000000;
    }
    printf("%d", res);
}

// keyword: DP
// 시간복잡도: O(N)
/*
idea: 맨 앞 자릿수에 따라 경우를 나눠서 점화식 세우고 계산
0도 포함, 단 최종 계산할 때는 0은 포함 X
*/