/*
    Rest Stops
    https://www.acmicpc.net/problem/15748
*/

#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int L, N, rf, rb;
pair<int,int> x[1000000];

int main() {
    int a, b, curpos = 0;
    long long res = 0;
    scanf("%d %d %d %d", &L, &N, &rf, &rb);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &a, &b);
        x[i] = make_pair(b, a);
    }
    sort(x, x+N);
    for(int i=N-1;i>=0;i--) {
        if (curpos < x[i].second) {
            res += (long long)x[i].first * (x[i].second - curpos) * (rf - rb);
            curpos = x[i].second;
        }
    }
    printf("%lld", res);
}

// keyword: 그리디 알고리즘, 정렬
// 시간복잡도: O(N) (정렬은 제외)
/*
idea: c가 큰 순서대로 우선 선택
다음으로 큰 것이 현재 bessie가 도달한 위치의 뒤에 있으면 res에 값 추가
*/