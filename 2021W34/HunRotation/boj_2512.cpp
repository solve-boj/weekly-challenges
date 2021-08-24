/*
    예산
    https://www.acmicpc.net/problem/2512
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, tot, m=0;
int plans[1000000];

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", plans+i);
        m = max(m, plans[i]);
    }
    scanf("%d", &tot);
    long long sum = 0;
    int l = 0, r = 1000000000, mid;
    while(l+1 < r) {
        sum = 0;
        mid = (l+r)/2;
        for(int i=0;i<N;i++) {
            if(plans[i] > mid) sum += mid;
            else sum += plans[i];
        }
        if(sum <= tot) l = mid;
        else r = mid;
    }
    printf("%d", min(m, l));
}

// keyword: 이분 탐색
// 시간복잡도: O(N log maxtot)
/*
idea: 구간을 설정하되, 왼쪽 끝은 조건을 반드시 만족하는 값, 오른쪽 끝은 반드시 불만족하는 값
중간값이 조건을 만족하면 새 왼쪽 값으로, 만족하지 않으면 새 오른쪽 값으로 설정
구간 크기가 1이 될때까지 반복해 조건 만족하는 경곗값을 구함
*/