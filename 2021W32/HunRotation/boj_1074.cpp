/*
    Z
    https://www.acmicpc.net/problem/1074
*/

#include <cstdio>
#include <cmath>

using namespace std;

int N, r, c;
int order[2][2] = {{0, 1},{2, 3}};

int f(int x, int xe, int y, int ye) {
    int L = (xe-x)/2;
    if (L == 0) {
        return 0;
    }
    //printf("<%d %d %d %d> %d\n", x, xe, y, ye, L*L*order[(r-x)/L][(c-y)/L]); 
    return L*L*order[(r-x)/L][(c-y)/L] + 
    f(x+(r-x)/L*L, x+((r-x)/L+1)*L, y+(c-y)/L*L, y+((c-y)/L+1)*L);
}

int main() {
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", f(0, (int)(pow(2, N)+0.01), 0, (int)(pow(2, N)+0.01)));
}

// keyword: DP? 분할정복?
// 시간복잡도: O(N)
/*
idea: 영역을 4개로 나눴을 때 주어진 위치가 어느 영역에 속하는지 파악
그 영역 앞에 방문하는 영역의 원소 수 더함
위치가 속하는 영역 내에서 같은 작업 반복
*/