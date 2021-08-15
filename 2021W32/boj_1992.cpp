/*
    쿼드트리
    https://www.acmicpc.net/problem/1992
*/

#include <cstdio>

using namespace std;

int vid[64][64] = {};
int N;

void f(int xstart, int xend, int ystart, int yend) {
    int zeros = 0, ones = 0;
    for(int i=xstart;i<xend;i++) {
        for(int j=ystart;j<yend;j++) {
            if(vid[i][j]) ones++;
            else zeros++;
        }
    }
    if(!ones) {
        printf("0");
        
    }
    else if(!zeros) {
        printf("1");
    }
    else {
        int xmid = (xstart + xend) / 2;
        int ymid = (ystart + yend) / 2;
        printf("(");
        f(xstart,xmid,ystart,ymid);
        f(xstart,xmid,ymid,yend);
        f(xmid,xend,ystart,ymid); 
        f(xmid,xend,ymid,yend);
        printf(")");

    }
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        char s[65];
        scanf("%s", s);
        for(int j=0;j<N;j++) {
            vid[i][j] = (s[j]=='1') ? 1 : 0;
        }
    }
    f(0,N,0,N);
}


// keyword: 분할 정복
// 시간복잡도: O(N log N)
/*
idea: 모든 숫자가 같으면 그 숫자 그대로 출력
다르면 4개의 영역으로 나눈 뒤 재귀 호출, 이 때 앞뒤에 괄호 붙임
*/