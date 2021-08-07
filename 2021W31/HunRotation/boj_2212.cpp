/*
    센서
    https://www.acmicpc.net/problem/2212
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
int pos[10000];
int dist[9999];
int sum=0;


int main() {
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i=0;i<N;i++) {
        scanf("%d", &pos[i]);
    }
    sort(pos, pos+N);
    for (int i=0;i<N-1;i++) {
        dist[i] = pos[i+1] - pos[i];
    }
    sort(dist, dist+N-1);
    for (int i=0;i<N-K;i++) {
        sum += dist[i];
    }
    printf("%d", sum);
}

// keyword: 그리디 알고리즘
// 시간복잡도: O(N log N)
/*
idea: 모든 센서를 한 번에 연결하는 선분 내에 있는
두 센서 사이 선분 중 가장 긴 K-1개를 골라 잘라냄
*/