/*
    나무 자르기
    https://www.acmicpc.net/problem/2805
*/

#include <cstdio>

using namespace std;

int N, M;
int trees[1000000];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%d", trees+i);
    }
    long long sum = 0;
    long long l = 0, r = 1000000000, mid;
    while(l+1 < r) {
        sum = 0;
        mid = (l+r)/2;
        for(int i=0;i<N;i++) {
            if(trees[i] > mid) sum += trees[i] - mid;
        }
        if(sum >= M) l = mid;
        else r = mid;
    }
    printf("%lld", l);
}

// keyword: 이분 탐색
// 시간복잡도: O(N log maxH)
/*
idea: 구간을 설정하되, 왼쪽 끝은 조건을 반드시 만족하는 값, 오른쪽 끝은 반드시 불만족하는 값
중간값이 조건을 만족하면 새 왼쪽 값으로, 만족하지 않으면 새 오른쪽 값으로 설정
구간 크기가 1이 될때까지 반복해 조건 만족하는 경곗값을 구함
*/