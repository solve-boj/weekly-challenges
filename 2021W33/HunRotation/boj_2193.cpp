/*
    이친수
    https://www.acmicpc.net/problem/2193
*/

#include <cstdio>

using namespace std;

int n;
long long memo[91][2];


long long f(int x, int first) {
    if (x==1) return 1LL;
    if (memo[x][first]) return memo[x][first];
    if (first == 0) return memo[x][first] = f(x-1, 0) + f(x-1, 1);
    else return memo[x][first] = f(x-1, 0);
}

int main() {
    scanf("%d", &n);
    printf("%lld", f(n, 1));
}

// keyword: DP
// 시간복잡도: O(N)
/*
idea: 0으로 시작하는 이친수 조건 만족하는 수의 개수, 1로 시작하는 이친수의 개수 나눠 생각
0으로 시작하는 경우 두 번째 자리는 0, 1 모두 가능
1로 시작하는 경우 두 번째 자리는 0만 가능
*/