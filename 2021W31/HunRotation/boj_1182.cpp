/*
    부분수열의 합
    https://www.acmicpc.net/problem/1182
*/

#include <cstdio>
#include <cmath>

using namespace std;

int n, s, cnt=0;
int arr[20];

int main() {
    int tempsum;
    scanf("%d %d\n", &n, &s);
    for (int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    for (int i=1;i<pow(2, n)-0.1;i++) {
        tempsum = 0;
        for (int j=0;j<n;j++) {
            if ((i >> j) & 1) {
                tempsum += arr[j];
            }
        }
        if (tempsum == s) {
            cnt++;
        }
    }
    printf("%d", cnt);
}

// keyword: 브루트 포스
// 시간복잡도: O(2^n)
/*
idea: 부분수열의 모든 경우를 따지기 위해서 bit masking을 이용
백트래킹으로도 가능한 것으로 보임, 나중에 다시 풀어보자
*/
