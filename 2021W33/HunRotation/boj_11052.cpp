/*
    카드 구매하기
    https://www.acmicpc.net/problem/11052
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int cost[1001];
int dp[1001];

int f(int x) {
    if(x==0) return 0;
    if(dp[x]) return dp[x];
    int res = cost[x];
    for(int i=1;i<=x-1;i++) {
        res = max(res, f(i) + cost[x-i]);
    }
    return dp[x] = res;
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &cost[i]);
    }
    printf("%d", f(N)); 
}

// keyword: DP
// 시간복잡도: O(N*2)
/*
idea: x개를 구입해야 하는 상황에서 i개짜리 카드덱을 구입하고 나머지를 최대가로 구입하는 경우
모두 계산해 최댓값 구함
*/