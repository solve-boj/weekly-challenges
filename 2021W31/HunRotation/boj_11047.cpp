/*
    동전 0
    https://www.acmicpc.net/problem/11047
*/

#include <cstdio>

using namespace std;

int N, K, cnt=0;
int values[10];

int main() {
    scanf("%d %d", &N, &K);
    for (int i=0;i<N;i++) {
        scanf("%d", &values[i]);
    }
    for (int i=N-1;i>=0;i--) {
        cnt += K/values[i];
        K -= K/values[i]*values[i];
    }
    printf("%d", cnt);
}

// keyword: 그리디 알고리즘
// 시간복잡도: O(N)
/*
idea: 값이 큰 동전부터 먼저 사용
*/