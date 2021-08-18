/*
    스티커
    https://www.acmicpc.net/problem/9465
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int tc, n;

int stickers[2][100000];
int memo[3][100000];
int used[3][100000];
int dp(int startline, int state, int tnum) {
    if(startline == n) return 0;

    if(tnum == used[state][startline]) return memo[state][startline];
    
    //printf("<%d %d>\n", startline, state);

    int res = dp(startline+1, 0, tnum);
    if(state != 1) res = max(res, dp(startline+1, 1, tnum) + stickers[0][startline]);
    if(state != 2) res = max(res, dp(startline+1, 2, tnum) + stickers[1][startline]);

    memo[state][startline] = res;
    used[state][startline]++;
    return res;
} 

int main() {
    int temp;
    scanf("%d", &tc);
    for(int i=0;i<tc;i++) {
        scanf("%d", &n);
        for(int j=0;j<2;j++) {
            for(int k=0;k<n;k++) {
                scanf("%d", &stickers[j][k]);
            }
        }
        for(int j=0;j<3;j++) {
            for(int k=0;k<n;k++) {
                memo[j][k] = 0;
            }
        }
        printf("%d\n", dp(0, 0, i+1));

    }

}

// 시간 최적화가 어려운 문제 - 잘 기억해 둘 것

// keyword: DP
// 시간복잡도: O(N)
/*
idea: 두 칸이 모두 떼어진 상태가 아닌 경우 state 0, 아래쪽이 떼어진 경우 state 1, 위쪽이 떼어진 경우 state 2
*/