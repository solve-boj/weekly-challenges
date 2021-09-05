/*
    K번째 수
    https://www.acmicpc.net/problem/1300
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, k;

int main() {
    scanf("%d%d", &N, &k);
    long long l=0, r=10000000001LL, mid, temp=0;
    while(l+1 < r) {
        temp=0;
        mid = (l+r)/2;
        for(int i=1;i<=min((long long)N, mid);i++) {
            temp += min((long long) N, (mid-1) / i);
        }
        //printf("%d %d %d\n", l, r, temp);
        if(temp <= k-1) l = mid;
        else r = mid;
    }
    printf("%d", l);
}

// keyword: 이분 탐색
// 시간복잡도: O(N^2 log N)
/*
idea: mid 미만인, 두 수 곱해 나올 수 있는 수의 개수를 셈
*/