/*
    공유기 설치
    https://www.acmicpc.net/problem/2110
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, C;
int coord[200000];

int main() {
    scanf("%d %d", &N, &C);
    for(int i=0;i<N;i++) {
        scanf("%d", coord+i);
    }
    sort(coord, coord+N);

    int cnt, mid, prev;
    int l = 1, r = 1000000000;
    while(l+1 < r) {
        cnt = 0;
        prev = -1000000000;
        mid = (l+r) / 2;
        for(int i=0;i<N;i++) {
            if (coord[i] - prev < mid) continue;
            ++cnt;
            prev = coord[i];
            if (cnt == C) break;
        }
        //printf("%d %d %d\n", l, r, cnt);
        if (cnt < C) r = mid;
        else l = mid;
    }
    printf("%d", l);
}

// keyword: 이분 탐색
// 시간복잡도: O(N log N)
/*
idea: mid 값이 임의로 설정한 두 공유기가 가지는 최소 거리 -> 이 값을 최대로 만들어야 함
*/