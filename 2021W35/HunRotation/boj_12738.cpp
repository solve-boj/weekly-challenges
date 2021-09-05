/*
    가장 긴 증가하는 부분 수열 3
    https://www.acmicpc.net/problem/12738
*/
// 2도 함께 해결 가능

#include <cstdio>
#include <algorithm>

int N;
int A[1000001];
int temp[1000001];

int bsearch(int end, int target) {
    int l=-1, r=end;
    int mid;
    while(l+1 < r) {
        mid = (l + r) / 2;
        if(temp[mid] == target) {
            return mid;
        }
        if(temp[mid] < target) l = mid;
        else r = mid;
    }
    return r;
}

using namespace std;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    int cnt = 1;
    temp[0] = A[0];
    for(int i=1;i<N;i++) {
        if(temp[cnt-1] < A[i]) {
            temp[cnt] = A[i];
            ++cnt;
        }
        else {
            temp[bsearch(cnt, A[i])] = A[i];
        }
        /*
        for(int i=0;i<cnt;i++) {
            printf("%d ", temp[i]);
        }
        printf("\n");
        */
    }
    printf("%d", cnt);
}

// keyword: 이분 탐색
// 시간복잡도: O(N log N)
/*
idea: 최대한 앞쪽 원소들을 작게 만들어야 수열을 길게 만들 수 있는 뒤쪽 수의 후보가 늘어남
따라서 새로운 원소를 기존에 만들어둔 수열과 비교
마지막 원소보다 그냥 추가
그렇지 않으면 적절한 위치에 끼워넣음
*/