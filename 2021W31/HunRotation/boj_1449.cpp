/*
    수리공 항승
    https://www.acmicpc.net/problem/1449
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, L;
int pos[1000];

int main() {
    scanf("%d %d\n", &N, &L);
    for(int i=0;i<N;i++) {
        scanf("%d", &pos[i]);
    }
    sort(pos, pos+N);
    int cur = 0, cnt = 0, prev;
    while (cur < N) {
        cnt++;
        prev = pos[cur];
        while(pos[cur] - prev < L) {
            cur++;
        }
    }
    printf("%d", cnt);
}
// keyword: 그리디 알고리즘
// 시간복잡도: O(N log N)
/*
idea: 한 지점에 테이프 끝(에서 0.5cm)을 둘 때 커버할 수 있는 영역을 모두 커버
*/