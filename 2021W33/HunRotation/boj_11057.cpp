/*
    오르막 수
    https://www.acmicpc.net/problem/11057
*/

#include <cstdio>

using namespace std;

int N;
int dp[1001][10];

int f(int x, int first) {
    if (x==1) return first + 1;
    if (first < 0) return 0;
    if (dp[x][first]) return dp[x][first];
    return dp[x][first] = (f(x, first - 1) + f(x-1, first)) % 10007; 
}

int main() {
    scanf("%d", &N);
    printf("%d", f(N, 9));
}

// keyword: DP
// 시간복잡도: O(N)
/*
idea: 맨 앞 자릿수가 first 이하인 x자리 오르막 수 개수가 f(x, first) 
*/