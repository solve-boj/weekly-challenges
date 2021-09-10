/*
    넴모넴모 2020
    https://www.acmicpc.net/problem/19845
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, Q;
int a[250001];
int x[250001];
int y[250001];
int l, r, mid;

int main() {
    scanf("%d %d", &N, &Q);
    for(int i=1;i<=N;i++) {
        scanf("%d", a+i);
    }
    for(int i=1;i<=Q;i++) {
        scanf("%d %d", x+i, y+i);
        l = y[i]-1; r = N+1;
        while(l+1<r) {
            mid = (l+r) / 2;
            if(a[mid] < x[i]) r = mid;
            else l = mid;
            //printf("[%d %d]\n", l, r);
        }
        printf("%d\n", l+1-y[i]+ max(0, a[y[i]] - x[i]));
    }

}

// keyword: 이분 탐색
// 시간복잡도: O(Q log N)
/*
idea: 
*/