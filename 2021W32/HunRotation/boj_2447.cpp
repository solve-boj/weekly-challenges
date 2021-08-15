/*
    별 찍기 - 10
    https://www.acmicpc.net/problem/2447
*/

#include <cstdio>

using namespace std;

char c[2187][2187];

void f(int x, int xe, int y, int ye) {
    if(xe-x==1) {
        c[x][y] = '*';
    }
    else {
        int L = (xe - x) / 3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(i!=1 || j!=1) {
                    f(x+L*i, x+L*(i+1), y+L*j, y+L*(j+1));
                }
            }
        }
    }
}

int N;
int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            c[i][j] = ' ';
        }
    }

    f(0, N, 0, N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
}

// keyword: 분할정복
// 시간복잡도: O(N^2 log N)
/*
idea: 처음에 모든 칸을 ' '로 채움
영역을 9개로 나누고 가운데 영역은 처리 X, 나머지는 별을 채움
이 과정을 영역을 계속 나누며 반복
*/