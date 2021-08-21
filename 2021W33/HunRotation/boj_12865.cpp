/*
    평범한 배낭
    https://www.acmicpc.net/problem/12865
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
int W[100];
int V[100];

int dp[100001][100];

int f(int num, int limit) {
    if(num >= N) return 0;
    if(dp[limit][num]) return dp[limit][num];
    return dp[limit][num] = max(f(num+1, limit), (W[num]>limit)?(0):(V[num] + f(num+1, limit-W[num])));
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &W[i], &V[i]);
    }
    printf("%d", f(0, K));
}

// keyword: DP
// 시간복잡도: O(NV)
/*
idea: 0번부터 번호 부여해 N번 물건 이후로만 limit 무게까지
담을 수 있을 때 최대 가치가 f(N, limit)
N번 물건을 포함하느냐 마느냐에 따라 경우가 나뉘고 점화식 세움
*/