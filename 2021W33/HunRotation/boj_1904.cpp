/*
    01타일
    https://www.acmicpc.net/problem/1904
*/
/*
    2×n 타일링
    https://www.acmicpc.net/problem/11726
*/

#include <cstdio>

using namespace std;

int N;
int dp[1000001];

int f(int x) {
    if (x==1) return 1;
    if (x==2) return 2;
    if (dp[x]) return dp[x];
    return dp[x] = (f(x-1) + f(x-2)) % 10007;
}

int main() {
    scanf("%d", &N);
    printf("%lld", f(N));
}


// keyword: DP
// 시간복잡도: O(N)
/*
idea: 사실상 피보나치 수열이다 이말이야
*/