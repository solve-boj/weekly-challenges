/*
    교환
    https://www.acmicpc.net/problem/1039
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
long long cnt = 0;
int board[15][15];

void f(int level) {
    //printf("%d %d %d\n", pos.first, pos.second, level);
    if(level==N) {
        ++cnt;
        return;
    }
    for(int i=0;i<N;i++) {
        if(board[level][i] == 0) {
            for(int j=1;j<N-level;j++) {
                ++board[level+j][i];
                if(i+j<N) ++board[level+j][i+j];
                if(i-j>=0) ++board[level+j][i-j];
            }
            f(level+1);
            for(int j=1;j<N-level;j++) {
                --board[level+j][i];
                if(i+j<N) --board[level+j][i+j];
                if(i-j>=0) --board[level+j][i-j];
            }
        }
    }
}   

int main() {
    scanf("%d", &N);

    f(0);
    printf("%lld", cnt);
}

