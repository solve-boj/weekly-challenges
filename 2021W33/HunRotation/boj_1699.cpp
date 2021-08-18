/*
    제곱수의 합
    https://www.acmicpc.net/problem/1699
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const short INF = 32000; 
int n;
short dp[320][100000];

// m은 사용할 최소 제곱수의 제곱근
short f(int x, int m) {
    if (m*m > x) return (x==0)?0:INF;
    if (dp[m][x]) return dp[m][x];
    return dp[m][x] = min(f(x, m+1), (short)(f(x-m*m, m)+1)); 
}

int main() {
    scanf("%d", &n);
    printf("%d", f(n, 1));
}

// keyword: DP
// 시간복잡도: O(N) (구하는 값이 항상 4 이하임이 수학적으로 증명됨)
/*
idea: base case는 이번에 더할 제곱수의 제곱근이 현재 값보다 큰 경우
현재 값이 0이면 0 return, 0이 아니면 불가능한 경우이므로 INF return
*/