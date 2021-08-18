/*
    2×n 타일링 2
    https://www.acmicpc.net/problem/11727
*/

#include <cstdio>

using namespace std;

int N;
int dp[1000001];

int f(int x) {
    if (x==1) return 1;
    if (x==2) return 3;
    if (dp[x]) return dp[x];
    return dp[x] = (f(x-1) + 2*f(x-2)) % 10007;
}

int main() {
    scanf("%d", &N);
    printf("%lld", f(N));
}


// keyword: DP
// 시간복잡도: O(N)
/*
idea: 점화식과 base case가 11726번에서 약간 바뀜
*/