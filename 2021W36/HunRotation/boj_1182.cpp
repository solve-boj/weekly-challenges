/*
    부분수열의 합
    https://www.acmicpc.net/problem/1182
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
int cnt = 0, cursum = 0;
int arr[20];

void bt(int cur) {
    if(cur == N) return;
    if(cursum + arr[cur] == S) cnt++;

    bt(cur+1);

    cursum += arr[cur];
    bt(cur+1);

    cursum -= arr[cur];
}

int main() {
    scanf("%d %d", &N, &S);
    for(int i=0;i<N;i++) {
        scanf("%d", arr+i);
    }
    bt(0);
    printf("%d", cnt);
}

// keyword: 백트래킹
// 시간복잡도: O(2^N)
/*
idea: 현재까지의 합에서 현재 원소 더한 값이 S이면 count
현재 원소를 합에 포함하지 않는 경우와 포함하는 경우 각각에 대해 재귀
*/