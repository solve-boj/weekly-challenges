/*
    도토리 숨기기
    https://www.acmicpc.net/problem/15732
*/

#include <cstdio>
#include <algorithm>

using namespace std;
int N, K, D;
int rule[10000][3];
int box[1000001];

int main() {
    int res, cnt=0;
    scanf("%d %d %d", &N, &K, &D);
    for(int i=0;i<K;i++) {
        scanf("%d %d %d", &rule[i][0], &rule[i][1], &rule[i][2]);
    }
    int l=0, r=N, mid, temp = 0;
    while (l+1 < r) {
        mid = (l+r)/2;
        long long temp = 0;
        for(int i=0;i<K;i++) {
            if(mid >= rule[i][0]) temp += (min(mid, rule[i][1]) - rule[i][0]) / rule[i][2] + 1;
        }
        //printf("%d %d %lld\n", l, r, temp);
        if(temp < D) l = mid;
        else r = mid;
    }
    printf("%d", r);
}

// keyword: 이분 탐색
// 시간복잡도: O(K log N)
/*
idea: 주어진 mid에 대해 여기까지 규칙을 이용해 채울수 있는 도토리의 개수를 셈(시간복잡도 O(K))
*/