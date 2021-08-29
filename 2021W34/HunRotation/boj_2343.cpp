/*
    기타 레슨
    https://www.acmicpc.net/problem/2343
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int lessons[100000];

int main() {
    int minans = 0, ans = 1000000000;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%d", &lessons[i]);
        minans = max(minans, lessons[i]);
    }
    int need = 0, temp = 0, cnt = 0;
    int l = minans-1, r = 1000000000, mid;
    while(l+1 < r) {
        //printf("%d %d\n", l, r);
        temp = 0;
        cnt = 0;
        mid = (l + r) / 2;
        for(int i=0;i<N;i++) {
            if(temp + lessons[i] > mid) {
                ++cnt;
                temp = 0;
            }
            temp += lessons[i];
        }
        ++cnt;
        if(cnt <= M) r = mid;
        else l = mid;
    }
    printf("%d", r);
}


// keyword: 이분 탐색
// 시간복잡도: O(N log N)
/*
idea: l, r 값을 조정하며 중앙값을 블루레이 크기로 지정했을 때 필요한 블루레이의 수를 직접 세어봄
*/